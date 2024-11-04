#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuildings.h"
#include <string>
#include <memory> // Include for smart pointers
#include "Government.h"
class factory : public IndustrialBuildings { // Class name updated to lowercase

public:
    // Constructor that initializes base class and factory-specific attributes
    factory(int x, int y, const std::string& district, int quality, int numWorkers, const std::string& factoryType, double production);

        // Copy constructor
    factory(const factory& other)
        : IndustrialBuildings(other), factoryType(other.factoryType) {} // Copy base and factory-specific attributes

    // Clone function
    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<factory>(*this);
    }


    void produceGoods();
    std::string getBuildingType();
    std::string getFactoryType();
    int getOccupancy();
    double getCost();
    double getMaintenanceCost();
    double getEnergyConsumption();
    double getWaterConsumption();
    void demolish();
    void upgrade(std::shared_ptr<BuildingComponent> building) override; // Changed to smart pointer
    double getArea();
    std::string getType() const override;

private:
    std::string factoryType; // Type of the factory
};

#endif
