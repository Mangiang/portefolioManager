/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *LoginLabel;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *errorLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(613, 527);
        LoginDialog->setMinimumSize(QSize(613, 527));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/images/login.svg"), QSize(), QIcon::Normal, QIcon::Off);
        LoginDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(LoginDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LoginLabel = new QLabel(LoginDialog);
        LoginLabel->setObjectName(QStringLiteral("LoginLabel"));
        LoginLabel->setMaximumSize(QSize(16777215, 20));
        LoginLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LoginLabel, 0, 0, 1, 2);

        usernameLineEdit = new QLineEdit(LoginDialog);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(usernameLineEdit, 2, 1, 1, 1);

        passwordLineEdit = new QLineEdit(LoginDialog);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 3, 1, 1, 1);

        usernameLabel = new QLabel(LoginDialog);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        gridLayout->addWidget(usernameLabel, 2, 0, 1, 1);

        passwordLabel = new QLabel(LoginDialog);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        gridLayout->addWidget(passwordLabel, 3, 0, 1, 1);

        errorLabel = new QLabel(LoginDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setEnabled(true);
        errorLabel->setMaximumSize(QSize(16777215, 20));
        errorLabel->setStyleSheet(QStringLiteral("color: red"));
        errorLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(errorLabel, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loginPushButton = new QPushButton(LoginDialog);
        loginPushButton->setObjectName(QStringLiteral("loginPushButton"));

        horizontalLayout->addWidget(loginPushButton);

        cancelPushButton = new QPushButton(LoginDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "LoginDialog", nullptr));
        LoginLabel->setText(QApplication::translate("LoginDialog", "LOGIN", nullptr));
        usernameLineEdit->setText(QString());
        usernameLineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "username", nullptr));
        passwordLineEdit->setPlaceholderText(QApplication::translate("LoginDialog", "password", nullptr));
        usernameLabel->setText(QApplication::translate("LoginDialog", "Username :", nullptr));
        passwordLabel->setText(QApplication::translate("LoginDialog", "Password :", nullptr));
        errorLabel->setText(QApplication::translate("LoginDialog", "Wrong username or password", nullptr));
        loginPushButton->setText(QApplication::translate("LoginDialog", "Login", nullptr));
        cancelPushButton->setText(QApplication::translate("LoginDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
