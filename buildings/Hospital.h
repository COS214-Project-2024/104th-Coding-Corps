#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "ServiceBuildings.h"
#include <string>

class Hospital : public ServiceBuildings {
private:
    int qualityOfCare;

public:
    Hospital(int quality, int numWorkers);

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
    int getQualityOfCare();
};

#endif
