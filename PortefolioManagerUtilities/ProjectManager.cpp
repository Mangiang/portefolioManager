#include "ProjectManager.h"
namespace PortefolioManagerUtilities {
	ProjectManager::ProjectManager(QObject *parent)
		: NetworkManager(parent)
	{
	}

	ProjectManager::~ProjectManager()
	{
	}

	bool ProjectManager::getProject(const QString& projectId) const
	{
		return get(QString("%1/api/project/detail/%2").arg(baseUrl).arg(projectId));
	}
}