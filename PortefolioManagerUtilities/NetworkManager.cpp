#include "NetworkManager.h"

#include <QDebug>

#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QHash>
#include <QException>

namespace PortefolioManagerUtilities {
	NetworkManager::NetworkManager(QObject *parent)
		: QObject(parent),
		manager(new QNetworkAccessManager(this)),
		baseUrl("https://arthur-joly.fr")

	{
		connect(manager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onRequestFinish(QNetworkReply*)));
	}

	bool NetworkManager::postUrlEncoded(const QString& url, const QHash<QString, QString>& body)
	{
		try
		{
			QByteArray paramByteArray = encodeParams(body);

			QNetworkRequest request(url);

			return sendPost(request, paramByteArray);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return false;
		}
		return true;
	}
	
	bool NetworkManager::put(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body)
	{
		try
		{
			QByteArray paramByteArray = encodeParams(body);

			QNetworkRequest request(url);

			QHashIterator<QString, QString> headerIterator(header);
			while (headerIterator.hasNext()) {
				headerIterator.next();
				request.setRawHeader(headerIterator.key().toUtf8(), headerIterator.value().toUtf8());
			}

			return sendPut(request, paramByteArray);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return false;
		}
	}

	QByteArray NetworkManager::encodeParams(const QHash<QString, QString>& body) const
	{
		QUrlQuery params;
		QHashIterator<QString, QString> bodyIterator(body);
		while (bodyIterator.hasNext()) {
			bodyIterator.next();
			params.addQueryItem(bodyIterator.key(), bodyIterator.value());
		}

		QString paramString = params.query(QUrl::FullyEncoded);
		paramString.replace("+", "%2B");
		return paramString.toUtf8();
	}

	bool NetworkManager::sendPost(QNetworkRequest& request, const QByteArray& params)
	{
		try
		{
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
			request.setHeader(QNetworkRequest::ContentLengthHeader, params.count());
				
			manager->post(request, params);
			return true;
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return false;
		}
	}
	
	bool NetworkManager::sendPut(QNetworkRequest& request, const QByteArray& params)
	{
		try
		{
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
			request.setHeader(QNetworkRequest::ContentLengthHeader, params.count());
				
			manager->put(request, params);
			return true;
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return false;
		}
	}

	bool NetworkManager::get(const QString& url) const
	{
		try
		{
			QNetworkRequest request(url);
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
			manager->get(request);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return false;
		}

		return true;
	}

	void NetworkManager::onRequestFinish(QNetworkReply* rep)
	{
		QVariant status = rep->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		if (!status.isValid())
			lastRequestStatusCode = 500;
		lastRequestStatusCode =  status.toInt();
		lastRequestMessage = rep->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
		lastRequestBody = rep->readAll();

		qDebug() << "Status " << getLastReplyStatusCode();
		qDebug() << "Message " << getLastReplyMessage();
		qDebug() << "Body " << getLastReplyBody();

		emit requestFinished();
	}
}