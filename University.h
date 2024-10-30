#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "ServiceBuildings.h"
#include <string>

class University : public ServiceBuildings {
private:
    int highestQualification;

public:
    University(int quality, int numWorkers, int highestQualification);

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    void upgrade(BuildingComponent* building) override;
    double getArea() override;
    int getHighestQualification();
};

#endif
