#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuildings.h"

class Warehouse : public IndustrialBuildings {

private:
	int storageCapacity;

public:
	Warehouse (int storageCapacity, int numWorkers)
		: IndustrialBuildings(numWorkers, 0.0)  // Calls the base class constructor with workers and default production
	{
		this->storageCapacity = storageCapacity;
	}
	
	//int storageCapacity;

    std::string getName() override {
        return "Warehouse";
    }

	double getStorageCapacity() {return 0;};

	string getBuildingType() {return "";};

	double getCost() {return 0;};

	double getMaintenanceCost() {return 0;};

	double getEnergyConsumption() {return 0;};

	double getWaterConsumption() {return 0;};

	void construct() {};

	void demolish() {};

	double getArea() {return 0;};

	void upgrade(BuildingComponent* building) {};

	int getOccupancy() {return 0;};
};

#endif
