#include <QDebug>
#include <QMessageBox>

#include "LoginDialog.h"
#include "LoginManager.h"
#include "User.h"
#include "NetworkReplyWrapper.h"

using namespace PortefolioManagerUtilities;

LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent),
	loginManager(new LoginManager(this))
{
	ui.setupUi(this);
	ui.errorLabel->setVisible(false);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint);

	connect(ui.cancelPushButton, &QPushButton::clicked, this, &LoginDialog::onCancelClicked);
	connect(ui.loginPushButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);

	getUserReply = new NetworkReplyWrapper(this);
	connect(getUserReply, &NetworkReplyWrapper::finishedProcessing, this, &LoginDialog::onLoginAnswer);
	
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
	
	getUserReply->setNetworkReply(loginManager->login(username, password));
}

void LoginDialog::onLoginAnswer(NetworkReplyWrapper* networkReplyWrapper)
{
	const int statusCode = getUserReply->getStatusCode();
	unlockInput();
	if (statusCode == 200)
	{
		qInfo() << "Successful login";
		user = QSharedPointer<User>(new User(User::fromJson(getUserReply->getBody())));

		if (!user->getAdmin())
			QMessageBox::warning( this, tr("Permission warning"), tr("This user is not an administrator. Feel free to experiment and preview but won't be able to submit any change."));

		accept();
	}
	else
	{
		qDebug() << "Wrong username or password";
		qDebug() << getUserReply->getBody();
		ui.errorLabel->setVisible(true);
	}
}