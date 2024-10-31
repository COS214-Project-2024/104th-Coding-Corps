#ifndef SERVICEBUILDINGFACTORY_H
#define SERVICEBUILDINGFACTORY_H

#include "BuildingFactory.h"
#include "ServiceBuildings.h"
#include <memory> // Include for smart pointers

class ServiceBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createSchool(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification) override;
    std::unique_ptr<BuildingComponent> createUniversity(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification) override;
    std::unique_ptr<BuildingComponent> createHospital(int x, int y, const std::string& district, int quality, int numWorkers) override;
};

#endif
