#pragma once

#include "portefoliomanagerutilities_global.h"

#include <QtGui/QTextCursor>

namespace PortefolioManagerUtilities {
	PORTEFOLIOMANAGERUTILITIES_EXPORT QTextCursor* wrapText(QTextCursor*, const QString);
	PORTEFOLIOMANAGERUTILITIES_EXPORT void formatHtml(QString&);
}