#include <QDebug>

#include "LoginDialog.h"
#include "LoginManager.h"
#include "User.h"

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
	
	unlockInput();
}

QSharedPointer<User> LoginDialog::getUser() const
{
	return user;
}

void LoginDialog::lockInput()
{
	ui.usernameLineEdit->setReadOnly(true);
	ui.passwordLineEdit->setReadOnly(true);
	ui.loginPushButton->setEnabled(false);
	ui.cancelPushButton->setEnabled(false);
}

void LoginDialog::unlockInput()
{
	ui.usernameLineEdit->setReadOnly(false);
	ui.passwordLineEdit->setReadOnly(false);
	ui.loginPushButton->setEnabled(true);
	ui.cancelPushButton->setEnabled(true);
}

void LoginDialog::onCancelClicked(bool checked /*= false*/)
{
	lockInput();
	reject();
}

void LoginDialog::onLoginClicked(bool checked /*= false*/)
{
	lockInput();
	const QString& username = ui.usernameLineEdit->text();
	const QString& password = ui.passwordLineEdit->text();

	ui.errorLabel->setVisible(false);
	
	loginManager->login(username, password);
}

void LoginDialog::onLoginAnswer()
{
 	const int statusCode = loginManager->getLastReplyStatusCode();
	unlockInput();
	if (statusCode == 200)
	{
		qInfo() << "Successful login";
		user = QSharedPointer<User>(new User(User::fromJson(loginManager->getLastReplyBody())));
		accept();
	}
	else
	{
		qDebug() << "Wrong username or password";
		qDebug() << loginManager->getLastReplyMessage();
		ui.errorLabel->setVisible(true);
	}
}