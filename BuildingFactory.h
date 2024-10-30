#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "BuildingComponent.h"
class BuildingFactory {

private:
	BuildingComponent* BuildingType;

public:
	virtual BuildingComponent* createFlat(int units, int residents, int floors, bool hasGarden) { return nullptr; }
	virtual BuildingComponent* createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) {return nullptr;}
	virtual BuildingComponent* createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units) {return nullptr;}
	virtual BuildingComponent* createFactory(int numWorkers, string factoryType, double production) {return nullptr;}
	virtual BuildingComponent* createPlant(int workers, double production) {return nullptr;}
	virtual BuildingComponent* createWarehouse(int storageCapacity, int numWorkers) {return nullptr;}
	virtual shared_ptr<BuildingComponent> createOffice(int numEmployees, string businessType, int x, int y, const std::string& district, int quality);
    virtual shared_ptr<BuildingComponent> createMall(int numShops, string businessType, int numBusinesses, int x, int y, const std::string& district, int quality);
    virtual shared_ptr<BuildingComponent> createShop(int shopSize, string businessType, int x, int y, const std::string& district, int quality);
	virtual BuildingComponent* createSchool(int highestQualification, int quality, int numWorkers) {return nullptr;}
	virtual BuildingComponent* createUniversity(int highestQualification, int quality, int numWorkers) {return nullptr;}
	virtual BuildingComponent* createHospital(int quality, int numWorkers) {return nullptr;}
};

#endif
