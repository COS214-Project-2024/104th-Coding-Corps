#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities {


public:
	virtual string getUtilityType() = 0;

	virtual double getConsumptionRate() = 0;

	virtual double getCost() = 0;

	virtual void activateUtility() = 0;

	virtual void deactivateUtility() = 0;
};

#endif
