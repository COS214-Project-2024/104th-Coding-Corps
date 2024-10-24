#ifndef PLANT_H
#define PLANT_H

class plant : IndustrialBuildings {

public:
	int electricityUnits;

	void generateElectricity(BuilldingComponent* building);

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();
};

#endif
