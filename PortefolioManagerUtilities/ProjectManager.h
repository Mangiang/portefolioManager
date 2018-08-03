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
		
		QNetworkReply* getImage(const QString& imageUrl) const;
		QNetworkReply* uploadImage(const QString& imagePath, const QString& projectId, const QString& token);
		QNetworkReply* deleteImage(const QString& imageId, const QString& projectId, const QString& token);
	private:
		const QString updateProjectUrl;
		const QString createProjectUrl;
		const QString detailProjectUrl;
		const QString uploadProjectImageUrl;
		const QString deleteProjectImageUrl;
	};
}