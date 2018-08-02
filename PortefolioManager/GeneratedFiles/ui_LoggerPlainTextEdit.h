/********************************************************************************
** Form generated from reading UI file 'LoggerPlainTextEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGERPLAINTEXTEDIT_H
#define UI_LOGGERPLAINTEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LoggerPlainTextEdit
{
public:

    void setupUi(QPlainTextEdit *LoggerPlainTextEdit)
    {
        if (LoggerPlainTextEdit->objectName().isEmpty())
            LoggerPlainTextEdit->setObjectName(QStringLiteral("LoggerPlainTextEdit"));
        LoggerPlainTextEdit->resize(400, 300);
        LoggerPlainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        LoggerPlainTextEdit->setReadOnly(true);

        retranslateUi(LoggerPlainTextEdit);

        QMetaObject::connectSlotsByName(LoggerPlainTextEdit);
    } // setupUi

    void retranslateUi(QPlainTextEdit *LoggerPlainTextEdit)
    {
        LoggerPlainTextEdit->setWindowTitle(QApplication::translate("LoggerPlainTextEdit", "LoggerPlainTextEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggerPlainTextEdit: public Ui_LoggerPlainTextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGERPLAINTEXTEDIT_H
