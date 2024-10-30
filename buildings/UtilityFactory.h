#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utilities.h"

class UtilityFactory {

public:
	virtual Utilities* createUtilityService() = 0;
};

#endif
