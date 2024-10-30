#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "BuildingComponent.h"
#include <memory> // Include the memory header for smart pointers
#include <string>

class BuildingFactory {
public:
    virtual std::unique_ptr<BuildingComponent> createFlat(int units, int residents, int floors, bool hasGarden) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createFactory(int numWorkers, const std::string& factoryType, double production) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createPlant(int workers, double production) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createWarehouse(int storageCapacity, int numWorkers) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createOffice(int numEmployees, const std::string& businessType) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createMall(int numShops, const std::string& businessType, int numBusinesses) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createShop(int shopSize, const std::string& businessType) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createSchool(int highestQualification, int quality, int numWorkers) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createUniversity(int highestQualification, int quality, int numWorkers) { return nullptr; }
    virtual std::unique_ptr<BuildingComponent> createHospital(int quality, int numWorkers) { return nullptr; }
};

#endif
