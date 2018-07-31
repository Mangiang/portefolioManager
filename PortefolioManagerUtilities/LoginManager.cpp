#include <QHash>

#include "LoginManager.h"

LoginManager::LoginManager(QObject *parent)
	: NetworkManager(parent)
{ }

void LoginManager::login(const QString& username, const QString& password)
{
	QHash<QString, QString> body;
	body.insert("username", username);
	body.insert("password", password);
	
	NetworkManager::postUrlEncoded(QString("%1%2").arg(this->baseUrl).arg("/api/login"), body);
}