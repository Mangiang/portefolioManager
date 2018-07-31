#pragma once

#include <QObject>

#include "portefoliomanagerutilities_global.h"

class QNetworkAccessManager;
class QNetworkReply;

class PORTEFOLIOMANAGERUTILITIES_EXPORT NetworkManager : public QObject
{
	Q_OBJECT

public:
	NetworkManager(QObject *parent);
	const int getLastReplyStatusCode() const;
	QString getLastReplayMessage() const;
private:
	QNetworkAccessManager* manager;
	QNetworkReply* lastReply;
protected:
	const QString baseUrl;
	void postUrlEncoded(const QString& url, const QHash<QString, QString>& body);

private slots:
	void onRequestFinish(QNetworkReply *rep);

signals:
	void finished();
};