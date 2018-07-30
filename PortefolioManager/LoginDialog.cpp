#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.errorLabel->setVisible(false);

	connect(ui.cancelPushButton, SIGNAL(clicked(bool)), SLOT(onCancelClicked(bool)));
	connect(ui.loginPushButton, SIGNAL(clicked(bool)), SLOT(onLoginClicked(bool)));
}

void LoginDialog::onCancelClicked(bool checked /*= false*/)
{
	reject();
}

void LoginDialog::onLoginClicked(bool checked /*= false*/)
{
	const QString& username = ui.usernameLineEdit->text();
	const QString& password = ui.passwordLineEdit->text();
	if (username == "test" && password == "test")
	{
		ui.errorLabel->setVisible(false);
		accept();
	}
	else
	{
		ui.errorLabel->setVisible(true);
	}
}
