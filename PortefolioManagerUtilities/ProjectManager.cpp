#include "ProjectManager.h"

#include <QDebug>
#include <QtNetwork/QNetworkRequest>
#include <QNetworkReply>

namespace PortefolioManagerUtilities {
	ProjectManager::ProjectManager(QObject *parent)
		: NetworkManager(parent),
		updateProjectUrl(QString("%1/api/project/update").arg(baseUrl)),
		createProjectUrl(QString("%1/api/project/create").arg(baseUrl)),
		detailProjectUrl(QString("%1/api/project/detail").arg(baseUrl)),
		uploadProjectImageUrl(QString("%1/api/project/upload").arg(baseUrl)),
		deleteProjectImageUrl(QString("%1/api/project/deleteImage").arg(baseUrl))
	{ }

	QNetworkReply* ProjectManager::getProject(const QString& projectId) const
	{
		return get(QString("%1/%2").arg(detailProjectUrl).arg(projectId));
	}

	QNetworkReply* ProjectManager::createProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project)
	{
		qDebug() << "Posting " << project;

		QHash<QString, QString> header;
		header.insert("Authorization", QString("Bearer %1").arg(token));

		return NetworkManager::postUrlEncoded(QString("%1/%2").arg(createProjectUrl).arg(projectId), header, project);
	}

	QNetworkReply* ProjectManager::uploadImage(const QString& imagePath, const QString& projectId, const QString& token)
	{
		QHash<QString, QString> header;
		header.insert("Authorization", QString("Bearer %1").arg(token));
		return NetworkManager::postMultipartFormData(imagePath, QString("%1/%2").arg(uploadProjectImageUrl).arg(projectId), header);
	}

	QNetworkReply* ProjectManager::getImage(const QString& imageUrl) const
	{
		return get(imageUrl);
	}

	QNetworkReply* ProjectManager::updateProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project)
	{
		qDebug() << "Putting " << project;

		QHash<QString, QString> header;
		header.insert("Authorization", QString("Bearer %1").arg(token));

		return NetworkManager::putUrlEncoded(QString("%1/%2").arg(updateProjectUrl).arg(projectId), header, project);
	}

	QNetworkReply * ProjectManager::deleteImage(const QString& imageId, const QString& projectId, const QString& token)
	{
		QHash<QString, QString> header;
		header.insert("Authorization", QString("Bearer %1").arg(token));

		return NetworkManager::deleteUrlEncoded(QString("%1/%2/%3").arg(deleteProjectImageUrl).arg(projectId).arg(imageId), header);
	}
}