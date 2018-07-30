#include "Logger.h"

#include <QtWidgets/QPlainTextEdit>

namespace PortefolioManagerUtilities {

	QPlainTextEdit* Logger::textEdit = 0;

	Logger::Logger(QObject *parent, QPlainTextEdit* textEdit)
		: QObject(parent)
	{
	}

	Logger::~Logger()
	{
		textEdit = nullptr;
	}

}