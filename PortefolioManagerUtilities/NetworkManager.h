#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>

#include "portefoliomanagerutilities_global.h"

class QNetworkReply;

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT NetworkManager : public QObject
	{
		Q_OBJECT

	public:
		NetworkManager(QObject *parent);
	private:
		QSharedPointer<QNetworkAccessManager> manager;
	protected:
		const QString baseUrl;
		
		/*! Implementation of a HTTP POST with url encoded body
		 */
		QNetworkReply* const postUrlEncoded(const QString& url, const QHash<QString, QString>& body);
		QNetworkReply* postUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body);

		/*! Implementation of a HTTP PUT with url encoded body
		 */
		QNetworkReply* putUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body);

		QByteArray encodeParams(const QHash<QString, QString>& body) const;
		QNetworkReply* const sendPost(QNetworkRequest& request, const QByteArray& params);
		QNetworkReply* sendPost(QNetworkRequest& request, QHttpMultiPart* const params);

		/*! Implementation of a HTTP PUT with byteArray
		 */
		QNetworkReply* sendPut(QNetworkRequest& request, const QByteArray& params);

		/*! Implementation of a HTTP DELETE 
		 */
		QNetworkReply * deleteUrlEncoded(const QString& url, const QHash<QString, QString>& header);
		QNetworkReply* sendDelete(QNetworkRequest& request);
		
		QNetworkReply* postMultipartFormData(const QString& filePath, const QString& url, const QHash<QString, QString>& header);

		/*! Implementation of a HTTP GET
		 *	Returns true on success, false otherwise
		 */
		QNetworkReply* get(const QString& url) const;
	};
}