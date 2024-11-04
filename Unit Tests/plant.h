#ifndef PLANT_H
#define PLANT_H

#include "IndustrialBuildings.h"
#include <memory> // Include for smart pointers
#include "Government.h"
class plant : public IndustrialBuildings { // Class name is in lowercase

public:
    // Constructor that initializes the base class with additional parameters
    plant(int x, int y, const std::string& district, int quality, double production, int workers);

    void generateElectricity(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    std::string getBuildingType();
    double getCost();
    double getMaintenanceCost();
    double getEnergyConsumption();
    double getWaterConsumption();
    void construct();
    void demolish();
    double getArea();
    void upgrade(std::shared_ptr<BuildingComponent> building); // Changed to smart pointer
    int getOccupancy();
};

#endif
