#include "PortefolioManagerUtilities.h"

QTextCursor* PortefolioManagerUtilities::wrapText(QTextCursor* cursor, const QString wrapTag)
{
	if (!cursor->hasSelection())
		return new QTextCursor();
	
	const int cursorStart = cursor->selectionStart();
	const int cursorEnd = cursor->selectionEnd();
	const int newCursorStart = cursorStart + 2 + wrapTag.length();
	const int newCursorEnd = newCursorStart + (cursorEnd - cursorStart);

	cursor->setPosition(cursorEnd);
	cursor->insertText(QString("</%1>").arg(wrapTag));
	cursor->setPosition(cursorStart);
	cursor->insertText(QString("<%1>").arg(wrapTag));

	cursor->setPosition(newCursorStart);
	cursor->setPosition(newCursorEnd, QTextCursor::KeepAnchor);

	return cursor;
}

PORTEFOLIOMANAGERUTILITIES_EXPORT void PortefolioManagerUtilities::formatHtml(QString& text)
{
	text.replace('\n', "");
}