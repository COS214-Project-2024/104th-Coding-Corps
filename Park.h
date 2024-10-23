#ifndef PARK_H
#define PARK_H

class Park : LandMarksBuildings {

public:
	double greenSpaceSize;

	string getBuildingType();

	void construct();

	double getGreenSpace();

	double getCost();

	double getMaintenanceCost();

	double getTourismRate();

	double getArea();
};

#endif
