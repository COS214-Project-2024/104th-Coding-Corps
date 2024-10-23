#ifndef LANDMARKSBUILDINGS_H
#define LANDMARKSBUILDINGS_H

class LandMarksBuildings : BuildingComponent {

public:
	double tourismRate;

	virtual string getBuildingType() = 0;

	virtual int getOccupancy() = 0;

	virtual double getCost() = 0;

	virtual double getMaintenanceCost() = 0;

	virtual double getEnergyConsumption() = 0;

	virtual double getWaterConsumption() = 0;

	virtual void construct() = 0;

	virtual void demolish() = 0;

	virtual void upgrade(BuildingComponent* building) = 0;

	virtual double getTourismRate() = 0;
};

#endif
