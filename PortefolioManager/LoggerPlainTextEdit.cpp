#include "LoggerPlainTextEdit.h"

#include <QFileInfo>
#include <QMessageLogger>

bool LoggerPlainTextEdit::logAutoScroll = true;
LoggerPlainTextEdit* LoggerPlainTextEdit::loggerTextEdit = 0;

LoggerPlainTextEdit::LoggerPlainTextEdit(QWidget *parent)
	: QPlainTextEdit(parent)
{
	ui.setupUi(this);
	loggerTextEdit = this;
	qInstallMessageHandler(customMessageHandler);
}

LoggerPlainTextEdit::~LoggerPlainTextEdit()
{
	loggerTextEdit = nullptr;
}

void LoggerPlainTextEdit::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
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
	if (loggerTextEdit)
	{
		const int previousPosition = loggerTextEdit->textCursor().position();

		loggerTextEdit->moveCursor(QTextCursor::End);
		loggerTextEdit->textCursor().insertHtml(logString);

		if (logAutoScroll)
			loggerTextEdit->moveCursor(QTextCursor::End);
		else
			loggerTextEdit->textCursor().setPosition(previousPosition);

	}
}
