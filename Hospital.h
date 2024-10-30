#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "ServiceBuildings.h"
#include <string>
#include <memory> // Include for smart pointers

class Hospital : public ServiceBuildings {
private:
    int qualityOfCare;

public:
    // Constructor that accepts coordinates, quality, and number of workers
    Hospital(int x, int y, const std::string& district, int quality, int numWorkers);

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    void upgrade(std::shared_ptr<BuildingComponent> building) override; // Use smart pointer
    double getArea() override;
    int getQualityOfCare();
};

#endif
