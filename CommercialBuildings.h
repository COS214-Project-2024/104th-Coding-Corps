#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H

class CommercialBuildings : BuildingComponent {

private:
	string businessType;
	int numBusinesses;

public:
	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void construct() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	virtual string getBusinessType() = 0;

	virtual int getNumBusinesses() = 0;
};

#endif
