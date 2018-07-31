#include "NetworkManager.h"

#include <QDebug>

#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>
#include <QHash>

NetworkManager::NetworkManager(QObject *parent)
	: QObject(parent),
	manager(new QNetworkAccessManager(this)),
	lastReply(nullptr),
	baseUrl("https://arthur-joly.fr")

{
	connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onRequestFinish(QNetworkReply*)));
}

void NetworkManager::postUrlEncoded(const QString& url, const QHash<QString, QString>& body)
{
	QUrlQuery params;
	QHashIterator<QString, QString> bodyIterator(body);
	while (bodyIterator.hasNext()) {
		bodyIterator.next();
		params.addQueryItem(bodyIterator.key(), bodyIterator.value());
	}
	
	QString paramString = params.query(QUrl::FullyEncoded);
	paramString.replace("+", "%2B");
	const QByteArray& paramByteArray = paramString.toUtf8();
	
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
	request.setHeader(QNetworkRequest::ContentLengthHeader, paramByteArray.count());

	manager->post(request, paramByteArray);
}

const int NetworkManager::getLastReplyStatusCode() const
{
	QVariant status = lastReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (!status.isValid())
		return 500;
	return status.toInt();
}

QString NetworkManager::getLastReplayMessage() const
{
	return lastReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
}

void NetworkManager::onRequestFinish(QNetworkReply *rep)
{
	lastReply = rep;
	emit finished();
}