#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "BuildingComponent.h"
#include <string>

using namespace std;

class CommercialBuildingFactory : public BuildingFactory {


public:
    BuildingComponent* createOffice(int numEmployees, string businessType);
	BuildingComponent* createMall(int numShops, string businessType, int numBusinesses);
	BuildingComponent* createShop(int shopSize, string businessType);
};

#endif
