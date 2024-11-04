#ifndef SERVICEBUILDINGS_H
#define SERVICEBUILDINGS_H

#include "BuildingComponent.h"
#include "Citizen.h"
#include <string>
#include <memory>

class ServiceBuildings : public BuildingComponent {

protected:
    int numWorkers;

public:
    // Constructor that initializes base attributes and derived class attributes
    ServiceBuildings(int x, int y, const std::string& district, int quality, int workers)
        : BuildingComponent(x, y, district, quality), numWorkers(workers) {}

    // Copy constructor
    ServiceBuildings(const ServiceBuildings& other)
        : BuildingComponent(other),    // Call base class copy constructor
        numWorkers(other.numWorkers) {}

    // Pure virtual clone function for derived classes to implement
    virtual std::shared_ptr<BuildingComponent> clone() const = 0;

    // Pure virtual functions that must be implemented by derived classes
    virtual std::string getBuildingType() override = 0;
    virtual int getOccupancy() override = 0;
    virtual double getCost() override = 0;
    virtual double getMaintenanceCost() override = 0;
    virtual double getEnergyConsumption() override = 0;
    virtual double getWaterConsumption() override = 0;
    virtual void upgrade(std::shared_ptr<BuildingComponent> building) override = 0;
    virtual double getArea() override = 0;

    // Additional methods specific to ServiceBuildings
    int getNumWorkers() const {
        return numWorkers;
    }
};

#endif // SERVICEBUILDINGS_H
