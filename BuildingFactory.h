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
	virtual BuildingComponent* createFactory(int numWorkers, string factoryType, double production) {}
	virtual BuildingComponent* createPlant(int workers, double production) {}
	virtual BuildingComponent* createWarehouse(int storageCapacity, int numWorkers) {}
	virtual BuildingComponent* createOffice() {}
	virtual BuildingComponent* createMall() {}
	virtual BuildingComponent* createShop() {}
};

#endif
