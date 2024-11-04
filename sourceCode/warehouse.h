#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "IndustrialBuildings.h"
#include <memory> // Include for smart pointers
#include "Government.h"
class Warehouse : public IndustrialBuildings { // Class name is retained as "Warehouse"

private:
    int storageCapacity; // Storage capacity of the warehouse

public:
    // Constructor that initializes the base class with additional parameters
    Warehouse(int x, int y, const std::string& district, int quality, int storageCapacity, int numWorkers);

        // Copy constructor
    Warehouse(const Warehouse& other)
        : IndustrialBuildings(other), // Call base class copy constructor
          storageCapacity(other.storageCapacity) {}

    // Clone function
    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<Warehouse>(*this);
    }

    double getStorageCapacity();
    std::string getBuildingType();
    double getCost();
    double getMaintenanceCost();
    double getEnergyConsumption();
    double getWaterConsumption();
    void construct();
    void demolish();
    std::string getType() const override {
        return "WareHouse"; // Return the specific type
    }
    double getArea();
    void upgrade(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    int getOccupancy();
};

#endif
