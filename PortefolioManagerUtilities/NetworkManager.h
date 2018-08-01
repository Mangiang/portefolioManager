#pragma once

#include <QObject>
#include <QSharedPointer>
#include "portefoliomanagerutilities_global.h"

class QNetworkAccessManager;
class QNetworkReply;

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT NetworkManager : public QObject
	{
		Q_OBJECT

	public:
		NetworkManager(QObject *parent);
		const int getLastReplyStatusCode() const;
		QString getLastReplyMessage() const;
		QString getLastReplyBody() const;
	private:
		QSharedPointer<QNetworkAccessManager> manager;
		QSharedPointer<QNetworkReply> lastReply;
	protected:
		const QString baseUrl;
		
		/*! Implementation of a HTTP POST
		 *	Returns true on success, false otherwise
		 */
		bool postUrlEncoded(const QString& url, const QHash<QString, QString>& body);
		
		/*! Implementation of a HTTP GET
		 *	Returns true on success, false otherwise
		 */
		bool get(const QString& url) const;

	private slots:
		void onRequestFinish(QNetworkReply* rep);

	signals:
		void requestFinished();
	};
}