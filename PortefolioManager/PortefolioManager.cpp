#include "PortefolioManager.h"

#include <QFileInfo>
#include <QTimer>
#include <QtWidgets/QMainWindow>
#include <QMessageLogger>

#include "PortefolioManagerUtilities.h"

QPlainTextEdit* PortefolioManager::logTextEdit = 0;
bool PortefolioManager::logAutoScroll = true;

PortefolioManager::PortefolioManager(QWidget *parent)
	: QMainWindow(parent),
	updateTimer(new QTimer(this)),
	loggedIn(false),
	loginDialog(nullptr)
{

	ui.setupUi(this);
	logTextEdit = ui.logPlainTextEdit;
	qInstallMessageHandler(customMessageHandler);
	
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
	connect(ui.actionShowLogin, SIGNAL(triggered(bool)), SLOT(onLoginDialogShow(bool)));

	// ToolBar actions
	connect(ui.actionBold, SIGNAL(triggered(bool)), SLOT(onBoldTriggered(bool)));
	connect(ui.actionItalic, SIGNAL(triggered(bool)), SLOT(onItalicTriggered(bool)));
	connect(ui.actionUnderline, SIGNAL(triggered(bool)), SLOT(onUnderlineTriggered(bool)));

	// Other actions
	connect(ui.webEngineView, SIGNAL(loadFinished(bool)), SLOT(onPageLoadFinished(bool)));
	connect(ui.webEngineView, SIGNAL(urlChanged(const QUrl&)), SLOT(onUrlChanged(const QUrl&)));
	connect(updateTimer.data(), SIGNAL(timeout()), this, SLOT(onUpdateTimeout()));
	
	loginDialog = QSharedPointer<LoginDialog>(new LoginDialog(this));
	connect(loginDialog.data(), SIGNAL(accepted()), SLOT(onLoginDialogAccepted()));
	connect(loginDialog.data(), SIGNAL(rejected()), SLOT(onLoginDialogRejected()));
	onLoginDialogShow();
}

void PortefolioManager::onLoginDialogAccepted()
{
	loggedIn = true;
	ui.webEngineView->setUrl(QUrl("https://arthur-joly.fr"));
}

void PortefolioManager::onLoginDialogRejected()
{
	loggedIn = false;
}

void PortefolioManager::onLoginDialogShow(bool)
{
	loginDialog->exec();
}

void PortefolioManager::onTogglePreview(bool) const
{
	ui.previewDockWidget->setVisible(!ui.previewDockWidget->isVisible());
	ui.previewDockWidget->setFloating(false);
}

void PortefolioManager::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QString typeStr;
	QString backgroundColor = "#FFFFFF";
	switch (type) {
	case QtDebugMsg:
		typeStr = "DEBUG";
		break;
	case QtInfoMsg:
		typeStr = "INFO";
		break;
	case QtWarningMsg:
		typeStr = "WARNING";
		backgroundColor = "#FF8100";
		break;
	case QtCriticalMsg:
		typeStr = "CRITICAL";
		backgroundColor = "#FF0000";
		break;
	case QtFatalMsg:
		typeStr = "FATAL";
		backgroundColor = "#FF0000";
		abort();
	}

#ifdef QT_DEBUG
	const QString& fileShortName = QFileInfo(context.file).fileName();

	QRegExp funcRegExp("\\s([^\\s]*)\\(");
	funcRegExp.indexIn(context.function);
	QStringList& list = funcRegExp.capturedTexts();
	QString functionShortName;
	if (list.length() > 0)
	{
		functionShortName = list[0].mid(1, list[0].length() - 2);
	}

	const QString& logString = QString("<span style=\"background-color: %1\">[%2] [%3] (%4:%5) %6</span><br/>\n").arg(backgroundColor).arg(typeStr).arg(functionShortName).arg(fileShortName).arg(context.line).arg(msg.toHtmlEscaped());
#else
	const QString& logString = QString("<span style=\"background-color: %1\">[%2] %3</span><br/>\n").arg(backgroundColor).arg(typeStr).arg(msg.toHtmlEscaped());
#endif
	if (logTextEdit)
	{
		const int previousPosition = logTextEdit->textCursor().position();

		logTextEdit->moveCursor(QTextCursor::End);
		logTextEdit->textCursor().insertHtml(logString);

		if (logAutoScroll)
			logTextEdit->moveCursor(QTextCursor::End);
		else
			logTextEdit->textCursor().setPosition(previousPosition);

	}
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
	ui.webEngineView->page()->runJavaScript(
		QString("var desc = document.getElementById('projectDescription'); "
			"if (desc) "
			"	desc.innerHTML = '%1'; ").arg(text));

}

void PortefolioManager::onPageLoadFinished(bool status) const
{
	if (status)
	{
		// Add a timer because PageLoadFinished is not always perfectly finished
		updateTimer->start(500);
	}
}

void PortefolioManager::onUrlChanged(const QUrl& newUrl) const
{
	ui.webEngineView->setUrl(newUrl);
}

void PortefolioManager::onUpdateTimeout() const
{
	ui.webEngineView->page()->runJavaScript(
		"var desc = document.getElementById('projectDescription');"
		"(desc ? desc.innerHTML :'')",
		[this](const QVariant &v) {
		ui.contentPlainTextEdit->clear();
		ui.contentPlainTextEdit->appendPlainText(v.toString());
		ui.contentPlainTextEdit->setReadOnly(false);
	});
	updateTimer->stop();
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