#ifndef PLANT_H
#define PLANT_H

#include "IndustrialBuildings.h"
#include <memory> // Include for smart pointers
#include "Government.h"
class plant : public IndustrialBuildings { // Class name is in lowercase

public:
    // Constructor that initializes the base class with additional parameters
    plant(int x, int y, const std::string& district, int quality, double production, int workers);

        // Copy constructor
    plant(const plant& other)
        : IndustrialBuildings(other) {} // Call base class copy constructor

    // Clone function
    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<plant>(*this);
    }

    void generateElectricity(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    std::string getBuildingType();
    double getCost();
    double getMaintenanceCost();
    double getEnergyConsumption();
    double getWaterConsumption();
    void construct();
    void demolish();
    std::string getType() const override {
        return "Plant"; // Return the specific type
    }
    double getArea();
    void upgrade(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    int getOccupancy();
};

#endif
