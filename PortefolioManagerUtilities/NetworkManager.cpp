#include "NetworkManager.h"

#include <QDebug>
#include <QException>
#include <QHash>
#include <QHttpPart>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QMimeDatabase>
#include <QMimeType>
#include <QFileInfo>

namespace PortefolioManagerUtilities {
	NetworkManager::NetworkManager(QObject *parent)
		: QObject(parent),
		manager(new QNetworkAccessManager(this)),
		baseUrl("https://arthur-joly.fr")
	{ }

	QNetworkReply* const NetworkManager::postUrlEncoded(const QString& url, const QHash<QString, QString>& body)
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
			return Q_NULLPTR;
		}
	}

	QNetworkReply* NetworkManager::postUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body)
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

			return sendPost(request, paramByteArray);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
		}
	}

	QNetworkReply* NetworkManager::putUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body)
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
		
			qDebug() << "To " << url;

			return sendPut(request, paramByteArray);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
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

	QNetworkReply* const NetworkManager::sendPost(QNetworkRequest& request, const QByteArray& params)
	{
		try
		{
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
			request.setHeader(QNetworkRequest::ContentLengthHeader, params.count());

			QNetworkReply* rep = manager->post(request, params);
			return rep;
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
		}
	}

	QNetworkReply* NetworkManager::sendPost(QNetworkRequest& request, QHttpMultiPart* const params)
	{
		try
		{
			return manager->post(request, params);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
		}
	}

	QNetworkReply* NetworkManager::sendPut(QNetworkRequest& request, const QByteArray& params)
	{
		try
		{
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
			request.setHeader(QNetworkRequest::ContentLengthHeader, params.count());

			return manager->put(request, params);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
		}
	}

	QNetworkReply* NetworkManager::postMultipartFormData(const QString& filePath, const QString& url, const QHash<QString, QString>& header)
	{
		QHttpMultiPart* const multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
		QHttpPart imagePart;

		QFileInfo fileInfo(filePath);
		QMimeDatabase db;
		QMimeType mime = db.mimeTypeForFile(filePath);
		imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(mime.name()));
		imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"" + fileInfo.baseName() + "\""));

		QFile *file = new QFile(filePath);
		if (!file->exists())
		{
			qDebug() << "File Does not exist";
		}

		file->open(QIODevice::ReadOnly);
		imagePart.setBodyDevice(file);
		file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart
		multiPart->append(imagePart);

		qDebug() << "Sending " << filePath;
		qDebug() << "To " << url;

		QNetworkRequest request(url);
		QHashIterator<QString, QString> headerIterator(header);
		while (headerIterator.hasNext()) {
			headerIterator.next();
			request.setRawHeader(headerIterator.key().toUtf8(), headerIterator.value().toUtf8());
		}
		QNetworkReply* reply = sendPost(request, multiPart);
		multiPart->setParent(reply);

		return reply;
	}

	QNetworkReply* NetworkManager::get(const QString& url) const
	{
		try
		{
			QNetworkRequest request(url);
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
			return manager->get(request);
		}
		catch (QException e)
		{
			qCritical() << e.what();
			return Q_NULLPTR;
		}
	}
}