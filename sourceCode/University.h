#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "ServiceBuildings.h"
#include <string>
#include <memory> // Include for smart pointers

class University : public ServiceBuildings {
private:
    int highestQualification;

public:
    // Constructor that accepts coordinates, quality, number of workers, and highest qualification
    University(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification);

    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<University>(*this);
    }

    std::string getBuildingType() override;
    int getOccupancy() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    std::string getType() const override {
        return "University"; // Return the specific type
    }
    void upgrade(std::shared_ptr<BuildingComponent> building) override; // Use shared_ptr
    double getArea() override;
    int getHighestQualification();
};

#endif
