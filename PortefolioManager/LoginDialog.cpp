#include <QDebug>

#include "LoginDialog.h"
#include "LoginManager.h"


LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent),
	loginManager(new PortefolioManagerUtilities::LoginManager(this))
{
	ui.setupUi(this);
	ui.errorLabel->setVisible(false);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint);

	connect(ui.cancelPushButton, SIGNAL(clicked(bool)), SLOT(onCancelClicked(bool)));
	connect(ui.loginPushButton, SIGNAL(clicked(bool)), SLOT(onLoginClicked(bool)));
	connect(loginManager, SIGNAL(requestFinished()), SLOT(onLoginAnswer()));
}

void LoginDialog::onCancelClicked(bool checked /*= false*/)
{
	reject();
}

void LoginDialog::onLoginClicked(bool checked /*= false*/)
{
	const QString& username = ui.usernameLineEdit->text();
	const QString& password = ui.passwordLineEdit->text();

	ui.errorLabel->setVisible(false);
	
	loginManager->login(username, password);
}

void LoginDialog::onLoginAnswer()
{
	const int statusCode = loginManager->getLastReplyStatusCode();

	if (statusCode == 200)
	{
		qInfo() << "Successful login";
		accept();
	}
	else
	{
		qDebug() << "Wrong username or password";
		qDebug() << loginManager->getLastReplyMessage();
		ui.errorLabel->setVisible(true);
	}
}