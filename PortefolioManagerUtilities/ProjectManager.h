#pragma once

#include "NetworkManager.h"

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT ProjectManager : public NetworkManager
	{
		Q_OBJECT

	public:
		ProjectManager(QObject *parent);
		bool getProject(const QString& projectId) const;
		bool updateProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project);
		bool createProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project);
		
		bool uploadImage(const QString& imagePath, const QString& projectId);
		bool getImage(const QString& imageUrl) const;
	private:
		const QString updateProjectUrl;
		const QString createProjectUrl;
		const QString detailProjectUrl;
		const QString uploadProjectImageUrl;
	};
}