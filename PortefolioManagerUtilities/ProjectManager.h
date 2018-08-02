#pragma once

#include "NetworkManager.h"

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT ProjectManager : public NetworkManager
	{
		Q_OBJECT

	public:
		ProjectManager(QObject *parent);
		~ProjectManager();
		bool getProject(const QString& projectId) const;
		bool updateProject(const QString& token, const QString& projectId, const QHash<QString, QString>& project);
	private:
		const QString updateProjectUrl;
		const QString detailProjectUrl;
	};
}