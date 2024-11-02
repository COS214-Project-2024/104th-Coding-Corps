#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingComponent.h"
#include "BuildingFactory.h"
#include <string>
#include <memory>

class IndustrialBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createFactory(int x, int y, const std::string& district, int quality, int numWorkers, const std::string& factoryType, double production) override;
    std::unique_ptr<BuildingComponent> createPlant(int x, int y, const std::string& district, int quality, double production, int workers) override;
    std::unique_ptr<BuildingComponent> createWarehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers) override;
};

#endif
