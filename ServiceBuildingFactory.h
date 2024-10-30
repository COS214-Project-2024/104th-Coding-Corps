#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ServiceBuildings.h"

class ServiceBuildingFactory : public BuildingFactory {
public:
    BuildingComponent* createSchool(int highestQualification, int quality, int numWorkers) override;
	BuildingComponent* createUniversity(int highestQualification, int quality, int numWorkers) override;
	BuildingComponent* createHospital(int quality, int numWorkers) override;
};

#endif
