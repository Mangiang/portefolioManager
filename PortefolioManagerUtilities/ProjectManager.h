#pragma once

#include "NetworkManager.h"

class QNetworkReply;

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT ProjectManager : public NetworkManager
	{
		Q_OBJECT

	public:
		ProjectManager(QObject *parent);
		QNetworkReply* getProject(const QString& projectId) const;
		QNetworkReply* updateProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project);
		QNetworkReply* createProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project);
		
		QNetworkReply* uploadImage(const QString& imagePath, const QString& projectId, const QString& token);
		QNetworkReply* getImage(const QString& imageUrl) const;
	private:
		const QString updateProjectUrl;
		const QString createProjectUrl;
		const QString detailProjectUrl;
		const QString uploadProjectImageUrl;
	};
}