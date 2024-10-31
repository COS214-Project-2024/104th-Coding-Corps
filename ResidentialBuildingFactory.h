#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ResidentialBuildings.h"
#include <memory> // Include for smart pointers
#include <string> // Include for std::string

class ResidentialBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createFlat(int units, int residents, int floors, bool hasGarden, const std::string& district, int quality) override;
    std::unique_ptr<BuildingComponent> createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, const std::string& district, int quality) override;
    std::unique_ptr<BuildingComponent> createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden, int units, const std::string& district, int quality) override;
};

#endif
