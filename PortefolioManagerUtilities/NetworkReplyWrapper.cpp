#include "NetworkReplyWrapper.h"
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

namespace PortefolioManagerUtilities {
	NetworkReplyWrapper::NetworkReplyWrapper(QObject* parent)
		:QObject(parent),
		data(new QHash<QString, QString>()),
		networkReply(nullptr)
	{ }

	NetworkReplyWrapper::~NetworkReplyWrapper()
	{
		delete data;
	}

	void NetworkReplyWrapper::setBody(const QByteArray& val)
	{
		body = val; 

		QJsonDocument bodyDoc = QJsonDocument::fromJson(val);
		QJsonObject bodyObj;

		// check validity of the document
		if (!bodyDoc.isNull())
		{
			if (bodyDoc.isObject())
			{
				bodyObj = bodyDoc.object();
				json = bodyObj.toVariantMap();
			}
			else
			{
				qDebug() << "Document is not an object" << endl;
			}
		}
		else
		{
			qDebug() << "Invalid JSON...\n" << endl;
		}
	}

	void NetworkReplyWrapper::setOperation()
	{
		switch (networkReply->operation()) {
		case QNetworkAccessManager::GetOperation:
			operation = ReplyOperation::GET;
			break;
		case QNetworkAccessManager::PostOperation:
			operation = ReplyOperation::POST;
			break;
		case QNetworkAccessManager::PutOperation:
			operation = ReplyOperation::PUT;
			break;
		default:
			operation = ReplyOperation::INVALID;
			break;
		}
	}

	void NetworkReplyWrapper::onFinish()
	{
		const QVariant& returnCode = networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		if (!returnCode.isValid())
			return setStatusCode(500);
		setStatusCode(returnCode.toInt());

		setMessage(networkReply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString());

		setBody(networkReply->readAll());

		networkReply->deleteLater();
		emit finishedProcessing(this);
	}

	void NetworkReplyWrapper::setNetworkReply(QNetworkReply* const networkReply)
	{
		this->data->clear();
		this->networkReply = networkReply;
		connect(this->networkReply, &QNetworkReply::finished, this, &NetworkReplyWrapper::onFinish);
	}
}