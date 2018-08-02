#pragma once

#include <QObject>
#include <QSharedPointer>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include "portefoliomanagerutilities_global.h"

class QNetworkReply;

namespace PortefolioManagerUtilities {
	enum ReplyOperation {
		GET, POST, PUT
	};

	class PORTEFOLIOMANAGERUTILITIES_EXPORT NetworkManager : public QObject
	{
		Q_OBJECT

	public:
		NetworkManager(QObject *parent);
		const int getLastReplyStatusCode() const { return lastRequestStatusCode; };
		QString getLastReplyMessage() const { return lastRequestMessage; };
		QString getLastReplyBody() const { return lastRequestBody; };
		ReplyOperation getLastReplyOperation() const { return lastRequestOperation; };
		void setLastReplyOperation(const QNetworkAccessManager::Operation& operation);
	private:
		QSharedPointer<QNetworkAccessManager> manager;
	protected:
		const QString baseUrl;
		
		/*! Implementation of a HTTP POST with url encoded body
		 *	Returns if no exception was raised
		 */
		bool postUrlEncoded(const QString& url, const QHash<QString, QString>& body);
		bool postUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body);

		/*! Implementation of a HTTP PUT with url encoded body
		 *	Returns if no exception was raised
		 */
		bool putUrlEncoded(const QString& url, const QHash<QString, QString>& header, const QHash<QString, QString>& body);

		QByteArray encodeParams(const QHash<QString, QString>& body) const;
		bool sendPost(QNetworkRequest& request, const QByteArray& params);
		bool sendPut(QNetworkRequest& request, const QByteArray& params);
		
		/*! Implementation of a HTTP GET
		 *	Returns true on success, false otherwise
		 */
		bool get(const QString& url) const;

		int lastRequestStatusCode;
		QString lastRequestMessage;
		QString lastRequestBody;
		ReplyOperation lastRequestOperation;
	private slots:
		void onRequestFinish(QNetworkReply* rep);

	signals:
		void requestFinished();
	};
}