#ifndef HOUSE_H
#define HOUSE_H

#include "ResidentialBuildings.h"
class House : public ResidentialBuildings {

private:
	int garageSize;
	bool pool;

public:
	House(int garageSize, bool hasPool, int x, int y, const std::string& district, int quality, int residents, int floors, bool hasGarden);

	int getGarageSize();

	bool hasSwimmingPool();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	int getNumResidents();

	int getNumFloors();

	bool hasGarden();

	double getArea();
	
	int getOccupancy() override;

	void upgrade(std::shared_ptr<BuildingComponent> building) override;
};

#endif
