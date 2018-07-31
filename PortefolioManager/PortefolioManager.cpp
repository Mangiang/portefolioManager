#include "PortefolioManager.h"

#include <QTimer>
#include <QtWidgets/QMainWindow>

#include "PortefolioManagerUtilities.h"

PortefolioManager::PortefolioManager(QWidget *parent)
	: QMainWindow(parent),
	loggedIn(false),
	loginDialog(nullptr)
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

	// Other actions
	connect(ui.webEngineView, SIGNAL(isReady()), SLOT(onPageReady()));

	loginDialog = QSharedPointer<LoginDialog>(new LoginDialog(this));
	connect(loginDialog.data(), SIGNAL(accepted()), SLOT(onLoginDialogAccepted()));
	connect(loginDialog.data(), SIGNAL(rejected()), SLOT(onLoginDialogRejected()));
	loginDialog->exec();
	
	projectSettingsDialog = QSharedPointer<ProjectSettingsDialog>(new ProjectSettingsDialog(this));
	connect(projectSettingsDialog.data(), SIGNAL(accepted()), SLOT(onLoginDialogAccepted()));
}

void PortefolioManager::onLoginDialogAccepted()
{
	loggedIn = true;
	ui.webEngineView->init();
}

void PortefolioManager::onLoginDialogRejected()
{
	loggedIn = false;
	close();
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

void PortefolioManager::onRefreshPreview(bool checked /*= false*/) const
{
	//ui.webEngineView->setHtml(ui.contentPlainTextEdit->toPlainText());
	QString& text = ui.contentPlainTextEdit->toPlainText();
	PortefolioManagerUtilities::formatHtml(text);

	ui.webEngineView->setContent("#projectDescription", text);
}

void PortefolioManager::onPageReady() const
{
	ui.webEngineView->getContent("#projectDescription",
		[this](const QVariant &v) {
		ui.contentPlainTextEdit->clear();
		ui.contentPlainTextEdit->appendPlainText(v.toString());
		ui.contentPlainTextEdit->setReadOnly(false);});
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

void PortefolioManager::onNewProjectTriggered(bool checked /*= false*/) const
{

}

void PortefolioManager::onNewProjectSettingsDialogAccepted()
{

}

void PortefolioManager::onProjectSettingsTriggered(bool checked /*= false*/) const
{

}

void PortefolioManager::onProjectSettingsDialogAccepted()
{

}