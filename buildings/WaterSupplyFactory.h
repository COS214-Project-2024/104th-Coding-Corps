#ifndef WATERSUPPLYFACTORY_H
#define WATERSUPPLYFACTORY_H

#include "UtilityFactory.h"

class WaterSupplyFactory : public UtilityFactory {

public:
	Utilities* createUtilityService();
};

#endif
