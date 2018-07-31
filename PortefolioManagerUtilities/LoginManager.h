#pragma once

#include <QObject>

#include "portefoliomanagerutilities_global.h"
#include "NetworkManager.h"

class NetworkManager;

class PORTEFOLIOMANAGERUTILITIES_EXPORT LoginManager : public NetworkManager
{
	Q_OBJECT

public:
	LoginManager(QObject *parent);
	void login(const QString&, const QString&);
};