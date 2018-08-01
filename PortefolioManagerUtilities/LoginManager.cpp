#include <QHash>

#include "LoginManager.h"

namespace PortefolioManagerUtilities {
	LoginManager::LoginManager(QObject *parent)
		: NetworkManager(parent)
	{ }

	bool LoginManager::login(const QString& username, const QString& password)
	{
		QHash<QString, QString> body;
		body.insert("login", username);
		body.insert("password", password);
		
		return NetworkManager::postUrlEncoded(QString("%1%2").arg(this->baseUrl).arg("/api/user/login"), body);
	}
}