#ifndef ESTATE_H
#define ESTATE_H

class Estate : public ResidentialBuildings {

private:
	int garageSize;
	bool hasSwimmingPool;

public:
	Estate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden);

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

	void upgrade(BuildingComponent* building) override;
};

#endif
