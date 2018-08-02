#include "ProjectManager.h"

#include <QDebug>
#include <QtNetwork/QNetworkRequest>

namespace PortefolioManagerUtilities {
	ProjectManager::ProjectManager(QObject *parent)
		: NetworkManager(parent),
		updateProjectUrl(QString("%1/api/project/update").arg(baseUrl)),
		detailProjectUrl(QString("%1/api/project/detail").arg(baseUrl))
	{
	}

	ProjectManager::~ProjectManager()
	{
	}

	bool ProjectManager::getProject(const QString& projectId) const
	{
		return get(QString("%1/%2").arg(detailProjectUrl).arg(projectId));
	}

	bool ProjectManager::updateProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project)
	{
		qDebug() << "Posting " << project;

		QHash<QString, QString> header;
		header.insert("Authorization", QString("Bearer %1").arg(token));

		return NetworkManager::put(QString("%1/%2").arg(updateProjectUrl).arg(projectId), header, project);
	}
}