#include "PortefolioManagerUtilities.h"


QString PortefolioManagerUtilities::wrapText(QTextCursor& cursor, const QString wrapTag)
{
	const int cursorStart = cursor.selectionStart();
	const int cursorEnd = cursor.selectionEnd();

	cursor.clearSelection();
	cursor.setPosition(cursorEnd, QTextCursor::MoveAnchor);
	cursor.insertText(QString("</%1>").arg(wrapTag));
	cursor.setPosition(cursorStart, QTextCursor::MoveAnchor);
	cursor.insertText(QString("<%1>").arg(wrapTag));

	return cursor.selectedText();
}