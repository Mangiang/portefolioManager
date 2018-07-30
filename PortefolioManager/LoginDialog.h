#pragma once

#include <QDialog>
#include "ui_LoginDialog.h"

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);

private:
	Ui::LoginDialog ui;

private slots:
	void onCancelClicked(bool checked = false);
	void onLoginClicked(bool checked = false);
};
