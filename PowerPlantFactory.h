#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilityFactory.h"

class PowerPlantFactory : public UtilityFactory {


public:
	Utilities* createUtilityService();
};

#endif
