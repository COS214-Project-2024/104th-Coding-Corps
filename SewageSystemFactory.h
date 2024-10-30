#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "UtilityFactory.h"

class SewageSystemFactory : public UtilityFactory {

public:
	Utilities* createUtilityService();
};

#endif
