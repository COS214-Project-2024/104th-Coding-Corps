#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ResidentialBuildings.h"
#include <memory> // Include for smart pointers

class ResidentialBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createFlat(int units, int residents, int floors, bool hasGarden) override;
    std::unique_ptr<BuildingComponent> createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) override;
    std::unique_ptr<BuildingComponent> createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units) override;
};

#endif
