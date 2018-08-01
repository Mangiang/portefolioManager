#pragma once

#include "NetworkManager.h"

class NetworkManager;

namespace PortefolioManagerUtilities {
	class PORTEFOLIOMANAGERUTILITIES_EXPORT LoginManager : public NetworkManager
	{
		Q_OBJECT

	public:
		LoginManager(QObject *parent);
		bool login(const QString& username, const QString& password);
	};
}