#include "IndustrialBuildingFactory.h"
#include "Factory.h"
#include "plant.h"
#include "warehouse.h"

BuildingComponent* IndustrialBuildingFactory::createFactory(int numWorkers, string factoryType, double production){
	return new Factory(numWorkers, factoryType, production);
}
BuildingComponent* IndustrialBuildingFactory::createPlant(int workers, double production){
	return new plant(workers, production);
}
BuildingComponent* IndustrialBuildingFactory::createWarehouse(int storageCapacity, int numWorkers) {
	return new Warehouse(storageCapacity, numWorkers);
}