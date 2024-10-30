#ifndef UTILITIES_H
#define UTILITIES_H

#include "string"
using namespace std;
class Utilities {
	
private:
	string utilityType;
	bool active;

public:
	Utilities(string type, bool active) : utilityType(type), active(active) {}

	string getUtilityType() { return utilityType; }

	virtual double getConsumptionRate() = 0;

	virtual double getCost() = 0;

	virtual void activateUtility() = 0;

	virtual void deactivateUtility() = 0;

	bool getStatus() { return active; }

	void changeStatus(bool status) {
		active = status;
	} 
};

#endif
