#include "NetworkReplyWrapper.h"
#include <QtNetwork/QNetworkReply>

namespace PortefolioManagerUtilities {
	NetworkReplyWrapper::NetworkReplyWrapper(QObject* parent)
		:QObject(parent),
		networkReply(nullptr)
	{ }

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
		this->networkReply = networkReply;
		connect(this->networkReply, &QNetworkReply::finished, this, &NetworkReplyWrapper::onFinish);
	}
}