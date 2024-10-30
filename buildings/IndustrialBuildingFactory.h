#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingComponent.h"
#include "BuildingFactory.h"
#include <string>
using namespace std;

class IndustrialBuildingFactory : public BuildingFactory {


public:
	BuildingComponent* createFactory(int numWorkers, string factoryType, double production) override;
	BuildingComponent* createPlant(int workers, double production) override;
	BuildingComponent* createWarehouse(int storageCapacity, int numWorkers) override;
};

#endif
