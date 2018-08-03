#pragma once

#include <QObject>
#include <QString>
#include <QHash>

#include "portefoliomanagerutilities_global.h"

class QNetworkReply;

namespace PortefolioManagerUtilities {
	enum PORTEFOLIOMANAGERUTILITIES_EXPORT ReplyOperation {
		GET, POST, PUT, INVALID
	};

	class PORTEFOLIOMANAGERUTILITIES_EXPORT NetworkReplyWrapper : public QObject
	{
		Q_OBJECT
	public:
		NetworkReplyWrapper(QObject* parent);
		~NetworkReplyWrapper();

		void setNetworkReply(QNetworkReply* const networkReply);

		int getStatusCode() const { return statusCode; }
		void setStatusCode(int val) { statusCode = val; }
		QString getMessage() const { return message; }
		void setMessage(const QString& val) { message = val; }
		QByteArray getBody() const { return body; }
		void setBody(const QByteArray& val) { body = val; }
		QString getOperation() const { return operation; }
		void setOperation();
		QString getData(const QString& key) const { return (*data)[key]; }
		void addData(const QString& key, const QString& value) { data->insert(key, value); }
	signals:
		void finishedProcessing(NetworkReplyWrapper* const networkReplyWrapper);
	private:
		QHash<QString, QString>* data;
		QNetworkReply * networkReply;
		int statusCode;
		QString message;
		QByteArray body;
		QString operation;
	private slots:
		void onFinish();
	};
};