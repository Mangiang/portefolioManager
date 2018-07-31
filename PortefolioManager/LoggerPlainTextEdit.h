#pragma once

#include <QPlainTextEdit>

#include "ui_LoggerPlainTextEdit.h"

class LoggerPlainTextEdit : public QPlainTextEdit
{
	Q_OBJECT

public:
	LoggerPlainTextEdit(QWidget *parent = Q_NULLPTR);
	~LoggerPlainTextEdit();

	/*! The method used to override the message handler*/
	static void customMessageHandler(QtMsgType, const QMessageLogContext&, const QString&);
	
	/*! The loggerTextEdit*/
	static LoggerPlainTextEdit* loggerTextEdit;
	
	/*! Does the log window autoscroll ?*/
	static bool logAutoScroll;

private:
	Ui::LoggerPlainTextEdit ui;
};
