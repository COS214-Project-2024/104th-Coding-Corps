#ifndef MONUMENT_H
#define MONUMENT_H

class monument : LandMarksBuildings {


public:
	void construct();

	void demolish();

	void upgrade(BuildingComponent* building);

	double getTourismRate();

	double getArea();

	string getBuildingType();
};

#endif
