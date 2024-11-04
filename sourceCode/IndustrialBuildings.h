#ifndef INDUSTRIALBUILDINGS_H
#define INDUSTRIALBUILDINGS_H

#include "BuildingComponent.h"
#include <string>
#include <memory>

class IndustrialBuildings : public BuildingComponent {

protected:
    double productionCapacity;
    int numWorkers;

public:
    // Constructor that calls the base constructor and initializes derived attributes
    IndustrialBuildings(int x, int y, const std::string& district, int quality, double production, int workers)
        : BuildingComponent(x, y, district, quality), productionCapacity(production), numWorkers(workers) {}

            // Copy constructor defined within the header file
    IndustrialBuildings(const IndustrialBuildings& other)
        : BuildingComponent(other),  // Call base class copy constructor
          productionCapacity(other.productionCapacity),
          numWorkers(other.numWorkers) {}

    // Pure virtual clone function, to be implemented in derived classes
    virtual std::shared_ptr<BuildingComponent> clone() const = 0;

    virtual std::string getBuildingType() = 0;
    virtual int getOccupancy() = 0;
    virtual double getCost() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual double getEnergyConsumption() = 0;
    virtual double getWaterConsumption() = 0;
    virtual void demolish() = 0;
    virtual void upgrade(std::shared_ptr<BuildingComponent> building) = 0;
    virtual double getArea() = 0;

    virtual double getProduction() const {
        return productionCapacity;
    }

    int getNumWorkers() const {
        return numWorkers;
    }
};

#endif // INDUSTRIALBUILDINGS_H
