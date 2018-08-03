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

PortefolioManager::PortefolioManager(QWidget *parent)
	: QMainWindow(parent),
	loginDialog(nullptr),
	projectManager(new PortefolioManagerUtilities::ProjectManager(this)),
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
	connect(ui.actionRefresh, SIGNAL(triggered(bool)), SLOT(onRefreshPreview(bool)));
	connect(ui.actionTogglePreview, SIGNAL(triggered(bool)), SLOT(onTogglePreview(bool)));
	connect(ui.actionToggleLog, SIGNAL(triggered(bool)), SLOT(onToggleLog(bool)));
	connect(ui.actionNewProject, SIGNAL(triggered(bool)), SLOT(onNewProjectTriggered(bool)));
	connect(ui.actionProjectSettings, SIGNAL(triggered(bool)), SLOT(onProjectSettingsTriggered(bool)));

	// ToolBar actions
	connect(ui.actionBold, SIGNAL(triggered(bool)), SLOT(onBoldTriggered(bool)));
	connect(ui.actionItalic, SIGNAL(triggered(bool)), SLOT(onItalicTriggered(bool)));
	connect(ui.actionUnderline, SIGNAL(triggered(bool)), SLOT(onUnderlineTriggered(bool)));
	connect(ui.actionSendContent, SIGNAL(triggered(bool)), SLOT(onSendContentTriggered(bool)));
	connect(ui.actionManageImages, SIGNAL(triggered(bool)), SLOT(onManageImages(bool)));

	// Other actions
	ui.webEngineView->page()->profile()->clearHttpCache();
	connect(ui.webEngineView, SIGNAL(isReady()), SLOT(onPageReady()));
	connect(ui.webEngineView, SIGNAL(isNotReady()), SLOT(onPageNotReady()));

	projectSettingsDialog = new ProjectSettingsDialog(this);

	manageImagesDialog = new ManageImagesDialog(this);

	loginDialog = new LoginDialog(this);
	connect(loginDialog, SIGNAL(accepted()), SLOT(onLoginDialogAccepted()));
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
	PortefolioManagerUtilities::formatHtml(text);

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
	PortefolioManagerUtilities::wrapText(cursor, "b");
}

void PortefolioManager::onItalicTriggered(bool checked /*= false*/) const
{
	QTextCursor* cursor = &ui.contentPlainTextEdit->textCursor();
	PortefolioManagerUtilities::wrapText(cursor, "i");
}

void PortefolioManager::onUnderlineTriggered(bool checked /*= false*/) const
{
	QTextCursor* cursor = &ui.contentPlainTextEdit->textCursor();
	PortefolioManagerUtilities::wrapText(cursor, "u");
}

void PortefolioManager::onSendContentTriggered(bool checked /*= false*/) const
{
	QHash<QString, QString> project;
	project.insert("description", ui.contentPlainTextEdit->toPlainText());
	connect(projectManager, SIGNAL(requestFinished()), SLOT(onUpdateFinished()), Qt::UniqueConnection);
	projectManager->updateProject(user->getToken(), getCurrentProjectID(), project);
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
	connect(projectSettingsDialog, SIGNAL(projectPosted()), SLOT(onProjectSettingsAccepted()), Qt::UniqueConnection);
	projectSettingsDialog->exec();
}

void PortefolioManager::onProjectSettingsTriggered(bool checked /*= false*/) const
{
	projectSettingsDialog->setProjectId(getCurrentProjectID());
	projectSettingsDialog->setToken(user->getToken());
	projectSettingsDialog->setIsAdmin(user->getAdmin());
	connect(projectSettingsDialog, SIGNAL(projectPosted()), SLOT(onProjectSettingsAccepted()), Qt::UniqueConnection);
	projectSettingsDialog->exec();
}

void PortefolioManager::onProjectSettingsAccepted()
{
	ui.webEngineView->reload();
}

void PortefolioManager::onUpdateFinished()
{
	ui.webEngineView->reload();
}