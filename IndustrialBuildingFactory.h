#ifndef INDUSTRIALBUILDINGFACTORY_H
#define INDUSTRIALBUILDINGFACTORY_H

#include "BuildingComponent.h"
#include "BuildingFactory.h"
#include <string>
using namespace std;

class IndustrialBuildingFactory : public BuildingFactory {


public:
	BuildingComponent* createFactory(int numEmployees, string businessType, int numBusinesses) override;
	BuildingComponent* createPlant(int numShops, string businessType, int numBusinesses) override;
	BuildingComponent* createWarehouse(int shopSize, string businessType, int numBusinesses) override;
};

#endif
