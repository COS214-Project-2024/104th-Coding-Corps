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
	virtual BuildingComponent* createOffice(int numEmployees, string businessType) {}
	virtual BuildingComponent* createMall(int numShops, string businessType, int numBusinesses) {}
	virtual BuildingComponent* createShop(int shopSize, string businessType) {}
	virtual BuildingComponent* createSchool(int highestQualification, int quality, int numWorkers) {}
	virtual BuildingComponent* createUniversity(int highestQualification, int quality, int numWorkers) {}
	virtual BuildingComponent* createHospital(int quality, int numWorkers) {}
};

#endif
