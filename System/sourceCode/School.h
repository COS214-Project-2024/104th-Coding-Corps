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

    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<School>(*this);
    }

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    std::string getType() const override {
        return "School"; // Return the specific type
    }
    void upgrade(std::shared_ptr<BuildingComponent> building) override; // Use smart pointer
    double getArea() override;
    int getHighestQualification();
};

#endif
