#pragma once

#include "portefoliomanagerutilities_global.h"

#include <QtGui/QTextCursor>

namespace PortefolioManagerUtilities {
	PORTEFOLIOMANAGERUTILITIES_EXPORT QTextCursor* wrapText(QTextCursor* cursor, const QString wrapTag);
	PORTEFOLIOMANAGERUTILITIES_EXPORT void formatHtml(QString& text);
}