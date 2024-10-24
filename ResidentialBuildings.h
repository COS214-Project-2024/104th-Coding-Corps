#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

class ResidentialBuildings : BuildingComponent {

private:
	int numResidents;
	int numFloors;
	bool hasGarden;

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

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();
};

#endif
