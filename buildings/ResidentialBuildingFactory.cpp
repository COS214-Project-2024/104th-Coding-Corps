#include "ResidentialBuildingFactory.h"
#include "BuildingComponent.h"
#include "Flat.h"
#include "House.h"
#include "Estate.h"

BuildingComponent* ResidentialBuildingFactory::createFlat(int units, int residents, int floors, bool hasGarden) {
	return new Flat(units, residents, floors, hasGarden);
}

BuildingComponent* ResidentialBuildingFactory::createHouse(int garageSize, bool hasPool, int residents, int floors, bool hasGarden){
	return new House(garageSize, hasPool, residents, floors, hasGarden);
}

BuildingComponent* ResidentialBuildingFactory::createEstate(int garageSize, bool hasPool, int residents, int floors, bool hasGarden){
	return new Estate(garageSize, hasPool, residents, floors, hasGarden);
}