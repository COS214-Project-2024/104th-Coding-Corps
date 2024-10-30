#ifndef SCHOOL_H
#define SCHOOL_H

#include "ServiceBuildings.h"
#include <string>

class School : public ServiceBuildings {
private:
    int highestQualification;

public:
    School(int quality, int numWorkers, int highestQualification);

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void construct() override;
    void demolish() override;
    void upgrade(BuildingComponent* building) override;
    double getArea() override;
    int getHighestQualification();
};

#endif
