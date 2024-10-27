#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "BuildingComponent.h"
class BuildingFactory {

private:
	BuildingComponent* BuildingType;

public:
	virtual BuildingComponent* createFlat(int units, int residents, int floors, bool hasGarden) {}
	virtual BuildingComponent* createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) {}
	virtual BuildingComponent* createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) {}
	virtual BuildingComponent* createFactory(int numEmployees, string businessType, int numBusinesses) {}
	virtual BuildingComponent* createPlant(int numShops, string businessType, int numBusinesses) {}
	virtual BuildingComponent* createWarehouse(int shopSize, string businessType, int numBusinesses) {}
	virtual BuildingComponent* createOffice() {}
	virtual BuildingComponent* createMall() {}
	virtual BuildingComponent* createShop() {}
};

#endif
