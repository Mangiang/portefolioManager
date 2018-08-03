#pragma once

#include <QDialog>
#include <QSharedPointer>
#include "ui_LoginDialog.h"

class User;

namespace PortefolioManagerUtilities {
	class LoginManager;
	class NetworkReplyWrapper;
}

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);
	QSharedPointer<User> getUser() const;
private:
	Ui::LoginDialog ui;
	PortefolioManagerUtilities::LoginManager* loginManager;
	QSharedPointer<User> user;
	PortefolioManagerUtilities::NetworkReplyWrapper* getUserReply;

	void lockInput();
	void unlockInput();
private slots:
	void onCancelClicked(bool checked = false);
	void onLoginClicked(bool checked = false);
	void onLoginAnswer(PortefolioManagerUtilities::NetworkReplyWrapper* networkReplyWrapper);
};
