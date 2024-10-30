#ifndef SCHOOL_H
#define SCHOOL_H

#include "ServiceBuildings.h"
#include <string>
#include <memory> // Include for smart pointers
#include "Government.h"
class School : public ServiceBuildings {
private:
    int highestQualification;

public:
    // Constructor that accepts coordinates, quality, number of workers, and highest qualification
    School(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification);

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    void upgrade(std::shared_ptr<BuildingComponent> building) override; // Use smart pointer
    double getArea() override;
    int getHighestQualification();
};

#endif
