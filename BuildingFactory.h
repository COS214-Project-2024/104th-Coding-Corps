#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

class BuildingFactory {

private:
	BuildingComponent* BuildingType;

public:
	virtual BuildingComponent* createBuilding() = 0;
};

#endif
