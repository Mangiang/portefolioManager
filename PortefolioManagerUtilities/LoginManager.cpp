#include <QHash>

#include "LoginManager.h"

namespace PortefolioManagerUtilities {
	LoginManager::LoginManager(QObject *parent)
		: NetworkManager(parent),
		specificUrl(QString("%1/api/user").arg(baseUrl))
	{ }

	QNetworkReply* const LoginManager::login(const QString& username, const QString& password)
	{
		QHash<QString, QString> body;
		body.insert("login", username);
		body.insert("password", password);
		
		return NetworkManager::postUrlEncoded(QString("%1/login").arg(specificUrl), body);
	}
}