#ifndef CULTURAL_CENTER_H
#define CULTURAL_CENTER_H

class Cultural_center : LandMarksBuildings {

public:
	int visitorCapacity;

	int getVisitorCapacity();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	void construct();

	void demolish();

	double getTourismRate();

	double getArea();
};

#endif
