#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ServiceBuildings.h"
#include <memory> // Include for smart pointers

class ServiceBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createSchool(int highestQualification, int quality, int numWorkers) override;
    std::unique_ptr<BuildingComponent> createUniversity(int highestQualification, int quality, int numWorkers) override;
    std::unique_ptr<BuildingComponent> createHospital(int quality, int numWorkers) override;
};

#endif
