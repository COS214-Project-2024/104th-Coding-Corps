#ifndef COMMERCIALBUILDINGFACTORY_H
#define COMMERCIALBUILDINGFACTORY_H

class CommercialBuildingFactory : BuildingFactory {


public:
	BuildingComponent* createBuilding();
};

#endif
