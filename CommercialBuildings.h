#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H

#include "BuildingComponent.h"
#include "string"

class CommercialBuildings : public BuildingComponent {

private:
	string businessType;
	int numBusinesses;

public:
	CommercialBuildings(string business, int num) { 
		this->businessType = business;
		this->numBusinesses = num;
	}
	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void construct() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	string getBusinessType() { return businessType; };

	int getNumBusinesses() { return numBusinesses;};
};

#endif
