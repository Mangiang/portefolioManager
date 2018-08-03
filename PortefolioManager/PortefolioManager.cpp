#include "PortefolioManager.h"

#include <QTimer>
#include <QtWidgets/QMainWindow>
#include <QWebEngineProfile>

#include "PortefolioManagerUtilities.h"
#include "LoginDialog.h"
#include "ProjectSettingsDialog.h"
#include "ProjectManager.h"
#include "ManageImagesDialog.h"
#include "User.h"
#include "NetworkReplyWrapper.h"

using namespace PortefolioManagerUtilities;

PortefolioManager::PortefolioManager(QWidget *parent)
	: QMainWindow(parent),
	loginDialog(nullptr),
	projectManager(new ProjectManager(this)),
	loggedIn(false),
	user(QSharedPointer<User>())
{
	ui.setupUi(this);
	
	// Setup Preview Dock Widget
	ui.previewDockWidget->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
	ui.previewDockWidget->setFloating(false);
	ui.previewDockWidget->setVisible(true);
	// Setup Log Dock Widget
	ui.logDockWidget->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
	ui.logDockWidget->setFloating(false);
	ui.logDockWidget->setVisible(false);

	// MenuBar actions
	connect(ui.actionRefresh, &QAction::triggered, this, &PortefolioManager::onRefreshPreview);
	connect(ui.actionTogglePreview, &QAction::triggered, this, &PortefolioManager::onTogglePreview);
	connect(ui.actionToggleLog, &QAction::triggered, this, &PortefolioManager::onToggleLog);
	connect(ui.actionNewProject, &QAction::triggered, this, &PortefolioManager::onNewProjectTriggered);
	connect(ui.actionProjectSettings, &QAction::triggered, this, &PortefolioManager::onProjectSettingsTriggered);

	// ToolBar actions
	connect(ui.actionBold, &QAction::triggered, this, &PortefolioManager::onBoldTriggered);
	connect(ui.actionItalic, &QAction::triggered, this, &PortefolioManager::onItalicTriggered);
	connect(ui.actionUnderline, &QAction::triggered, this, &PortefolioManager::onUnderlineTriggered);
	connect(ui.actionSendContent, &QAction::triggered, this, &PortefolioManager::onSendContentTriggered);
	connect(ui.actionManageImages, &QAction::triggered, this, &PortefolioManager::onManageImages);

	// Other actions
	ui.webEngineView->page()->profile()->clearHttpCache();
	connect(ui.webEngineView, &PreviewWebEngineView::isReady, this, &PortefolioManager::onPageReady);
	connect(ui.webEngineView, &PreviewWebEngineView::isNotReady,this, &PortefolioManager::onPageNotReady);

	projectSettingsDialog = new ProjectSettingsDialog(this);

	manageImagesDialog = new ManageImagesDialog(this);

	updateProjectReply = new NetworkReplyWrapper(this);
	
	loginDialog = new LoginDialog(this);
	connect(loginDialog, &LoginDialog::accepted, this, &PortefolioManager::onLoginDialogAccepted);
	loginDialog->show();
}

void PortefolioManager::closeEvent(QCloseEvent *event)
{
	loginDialog->close();
	ui.logDockWidget->close();
	ui.previewDockWidget->close();
}

QString PortefolioManager::getCurrentProjectID() const
{
	const QString& path = ui.webEngineView->getPath();
	const QStringList& pathList = path.split('/');
	const QString& projectId = pathList.last();

	return projectId;
}

void PortefolioManager::onLoginDialogAccepted()
{
	user = loginDialog->getUser();
	loggedIn = true;
	ui.webEngineView->init();
	show();
}

void PortefolioManager::onTogglePreview(bool) const
{
	ui.previewDockWidget->setVisible(!ui.previewDockWidget->isVisible());
	ui.previewDockWidget->setFloating(false);
}


void PortefolioManager::onToggleLog(bool) const
{
	ui.logDockWidget->setVisible(!ui.logDockWidget->isVisible());
	ui.logDockWidget->setFloating(false);
}

void PortefolioManager::onRefreshPreview(bool) const
{
	QString& text = ui.contentPlainTextEdit->toPlainText();
	formatHtml(text);

	ui.webEngineView->setHtmlTagContent("#projectDescription", text);
}

void PortefolioManager::onPageReady() const
{
	ui.webEngineView->getHtmlTagContent("#projectDescription",
		[this](const QVariant &v) {
		ui.contentPlainTextEdit->clear();
		ui.contentPlainTextEdit->appendPlainText(v.toString());

		ui.contentPlainTextEdit->setReadOnly(false);
		ui.actionProjectSettings->setEnabled(true);
	});
}

void PortefolioManager::onPageNotReady() const
{
	ui.contentPlainTextEdit->setReadOnly(true);
	ui.actionProjectSettings->setEnabled(false);
}

void PortefolioManager::onBoldTriggered(bool checked /*= false*/) const
{
	QTextCursor* cursor = &ui.contentPlainTextEdit->textCursor();
	wrapText(cursor, "b");
}

void PortefolioManager::onItalicTriggered(bool checked /*= false*/) const
{
	QTextCursor* cursor = &ui.contentPlainTextEdit->textCursor();
	wrapText(cursor, "i");
}

void PortefolioManager::onUnderlineTriggered(bool checked /*= false*/) const
{
	QTextCursor* cursor = &ui.contentPlainTextEdit->textCursor();
	wrapText(cursor, "u");
}

void PortefolioManager::onSendContentTriggered(bool checked /*= false*/) const
{
	QHash<QString, QString> project;
	project.insert("description", ui.contentPlainTextEdit->toPlainText());
	updateProjectReply->setNetworkReply(projectManager->updateProject(user->getToken(), getCurrentProjectID(), project));
	connect(projectManager, SIGNAL(finished(NetworkReplyWrapper*)), SLOT(onUpdateFinished(NetworkReplyWrapper*)), Qt::UniqueConnection);
}

void PortefolioManager::onManageImages(bool checked /*= false*/) const
{
	manageImagesDialog->setToken(user->getToken());
	manageImagesDialog->setIsAdmin(user->getAdmin());
	manageImagesDialog->getImages(getCurrentProjectID());
	manageImagesDialog->exec();
}

void PortefolioManager::onNewProjectTriggered(bool checked /*= false*/) const
{
	projectSettingsDialog->setToken(user->getToken());
	projectSettingsDialog->setIsAdmin(user->getAdmin());
	projectSettingsDialog->init();
	connect(projectSettingsDialog, &ProjectSettingsDialog::projectPosted, this, &PortefolioManager::onProjectSettingsAccepted, Qt::UniqueConnection);
	projectSettingsDialog->exec();
}

void PortefolioManager::onProjectSettingsTriggered(bool checked /*= false*/) const
{
	projectSettingsDialog->setProjectId(getCurrentProjectID());
	projectSettingsDialog->setToken(user->getToken());
	projectSettingsDialog->setIsAdmin(user->getAdmin());
	connect(projectSettingsDialog, &ProjectSettingsDialog::projectPosted, this, &PortefolioManager::onProjectSettingsAccepted, Qt::UniqueConnection);
	projectSettingsDialog->exec();
}

void PortefolioManager::onProjectSettingsAccepted()
{
	ui.webEngineView->reload();
}

void PortefolioManager::onUpdateFinished(NetworkReplyWrapper* networkReplyWrapper)
{
	ui.webEngineView->reload();
}