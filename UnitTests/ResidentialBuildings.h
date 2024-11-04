#ifndef RESIDENTIALBUILDINGS_H
#define RESIDENTIALBUILDINGS_H

#include "BuildingComponent.h"
#include <string>
#include <memory>

class ResidentialBuildings : public BuildingComponent {

protected:
    int numResidents;
    int numFloors;
    bool garden;

public:
    // Constructor that calls the base constructor and initializes derived attributes
    ResidentialBuildings(int x, int y, const std::string& district, int quality, int residents, int floors, bool hasGarden)
        : BuildingComponent(x, y, district, quality), numResidents(residents), numFloors(floors), garden(hasGarden) {}

    // Pure virtual functions inherited from BuildingComponent
    virtual std::string getBuildingType() = 0;
    virtual int getOccupancy() = 0;
    virtual double getCost() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual double getEnergyConsumption() = 0;
    virtual double getWaterConsumption() = 0;
    virtual void demolish() = 0;
    virtual void upgrade(std::shared_ptr<BuildingComponent> building) = 0;

    // Additional methods specific to ResidentialBuildings
    int getNumResidents() const {
        return numResidents;
    }

    int getNumFloors() const {
        return numFloors;
    }

    bool hasGarden() const {
        return garden;
    }
};

#endif // RESIDENTIALBUILDINGS_H
