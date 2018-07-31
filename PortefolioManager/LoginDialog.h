#pragma once

#include <QDialog>
#include <QSharedPointer>
#include "ui_LoginDialog.h"

class LoginManager;

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoginDialog ui;
	QSharedPointer<LoginManager> loginManager;

private slots:
	void onCancelClicked(bool checked = false);
	void onLoginClicked(bool checked = false);
	void onLoginAnswer();
};
