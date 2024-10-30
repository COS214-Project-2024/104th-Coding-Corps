#ifndef WASTEMANEGEMENTFACTORY_H
#define WASTEMANEGEMENTFACTORY_H

#include "UtilityFactory.h"

class WasteManegementFactory : public UtilityFactory {

public:
	Utilities* createUtilityService();
};

#endif
