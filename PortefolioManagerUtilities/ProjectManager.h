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
};
}