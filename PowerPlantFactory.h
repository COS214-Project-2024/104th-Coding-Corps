#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

class PowerPlantFactory : UtilityFactory {


public:
	Utilities* createUtilityService();
};

#endif
