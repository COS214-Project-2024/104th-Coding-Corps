#ifndef WASTEMANEGEMENTFACTORY_H
#define WASTEMANEGEMENTFACTORY_H

class WasteManegementFactory : UtilityFactory {


public:
	Utilities* createUtilityService();
};

#endif
