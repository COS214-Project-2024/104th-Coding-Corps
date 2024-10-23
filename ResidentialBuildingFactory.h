#ifndef RESIDENTIALBUILDINGFACTORY_H
#define RESIDENTIALBUILDINGFACTORY_H

class ResidentialBuildingFactory : BuildingFactory {


public:
	BuildingComponent* createBuilding();
};

#endif
