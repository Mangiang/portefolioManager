#include "User.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

User::User()
{
}

User::User(const User& otherUser)
{
	setFirstname(otherUser.firstname);
	setLastname(otherUser.lastname);
	setLastname(otherUser.lastname);
	setPhone(otherUser.phone);
	setToken(otherUser.token);
	setAdmin(otherUser.admin);
}

User User::fromJson(const QString& data)
{
	User user;

	QJsonObject obj;
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	if (!doc.isNull())
	{
		if (doc.isObject())
		{
			obj = doc.object();
		}
		else
		{
			qDebug() << "Document is not an object";
			return user;
		}
	}
	else
	{
		qDebug() << "Invalid JSON...";
		qDebug() << "Received " << data;
		return user;
	}

	QJsonObject userObj;
	const QVariantMap& objectMap = obj.toVariantMap();
	if (!objectMap["success"].toBool())
	{
		qDebug() << "Request has failed";
		return user;
	}

	const QVariantMap& userMap = objectMap["user"].toMap();

	user.setFirstname(userMap["firstname"].toString());
	user.setLastname(userMap["lastname"].toString());
	user.setPhone(userMap["phone"].toString());
	user.setAdmin(userMap["admin"].toBool());
	user.setToken(objectMap["token"].toString());

	return user;
}
