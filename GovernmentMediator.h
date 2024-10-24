#ifndef GOVERNMENTMEDIATOR_H
#define GOVERNMENTMEDIATOR_H
#include "AbstractCitizen.h"

class GovernmentMediator {


public:
	virtual void notify(AbstractCitizen* citizen) = 0;
};

#endif
