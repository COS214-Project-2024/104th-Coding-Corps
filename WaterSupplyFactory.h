#ifndef WATERSUPPLYFACTORY_H
#define WATERSUPPLYFACTORY_H

class WaterSupplyFactory : UtilityFactory {


public:
	Utilities* createUtilityService();
};

#endif
