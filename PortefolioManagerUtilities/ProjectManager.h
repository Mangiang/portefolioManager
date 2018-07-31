#pragma once

#include "NetworkManager.h"

class PORTEFOLIOMANAGERUTILITIES_EXPORT ProjectManager : public NetworkManager
{
	Q_OBJECT

public:
	ProjectManager(QObject *parent);
	~ProjectManager();
};
