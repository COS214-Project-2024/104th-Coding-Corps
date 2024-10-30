#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "BuildingComponent.h"
#include <string>
#include <memory> // Include memory for smart pointers

using namespace std;

class CommercialBuildingFactory : public BuildingFactory {

public:
    shared_ptr<BuildingComponent> createOffice(int numEmployees, string businessType, int x, int y, const std::string& district, int quality);
    shared_ptr<BuildingComponent> createMall(int numShops, string businessType, int numBusinesses, int x, int y, const std::string& district, int quality);
    shared_ptr<BuildingComponent> createShop(int shopSize, string businessType, int x, int y, const std::string& district, int quality);
};

#endif
