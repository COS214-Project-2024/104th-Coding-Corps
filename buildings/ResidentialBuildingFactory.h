#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ResidentialBuildings.h"

class ResidentialBuildingFactory : public BuildingFactory {


public:
	BuildingComponent* createFlat(int units, int residents, int floors, bool hasGarden) override;
	BuildingComponent* createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) override;
	BuildingComponent* createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden) override;
};

#endif
