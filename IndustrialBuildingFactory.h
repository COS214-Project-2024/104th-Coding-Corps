#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingComponent.h"
#include "BuildingFactory.h"
#include <string>
#include <memory> 

class IndustrialBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createFactory(int numWorkers, const std::string& factoryType, double production) override;
    std::unique_ptr<BuildingComponent> createPlant(int workers, double production) override;
    std::unique_ptr<BuildingComponent> createWarehouse(int storageCapacity, int numWorkers) override;
};

#endif
