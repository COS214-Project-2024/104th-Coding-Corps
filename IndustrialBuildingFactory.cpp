#include "IndustrialBuildingFactory.h"
#include "Factory.h"
#include "plant.h"
#include "warehouse.h"

BuildingComponent* IndustrialBuildingFactory::createFactory(int numEmployees, string businessType, int numBusinesses){
	return new Factory(numEmployees, businessType, numBusinesses);
}
BuildingComponent* IndustrialBuildingFactory::createPlant(int numShops, string businessType, int numBusinesses){
	return new plant(numShops, businessType, numBusinesses);
}
BuildingComponent* IndustrialBuildingFactory::createWarehouse(int shopSize, string businessType, int numBusinesses) {
	return new Warehouse(shopSize, businessType, numBusinesses);
}