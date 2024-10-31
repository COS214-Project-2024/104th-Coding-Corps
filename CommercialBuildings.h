#ifndef COMMERCIALBUILDINGS_H
#define COMMERCIALBUILDINGS_H

#include "BuildingComponent.h"
#include <string>
#include <memory>

class CommercialBuildings : public BuildingComponent {

private:
    std::string businessType;
    int numBusinesses;

public:
    // Constructor that calls the base constructor and initializes derived attributes
    CommercialBuildings(int x, int y, const std::string& district, int quality, const std::string& business, int num)
        : BuildingComponent(x, y, district, quality), businessType(business), numBusinesses(num) {}

    // Pure virtual functions that must be implemented by derived classes
    virtual std::string getBuildingType() = 0;
    virtual int getOccupancy() = 0;
    virtual double getCost() = 0;
    virtual double getMaintenanceCost() = 0;
    virtual double getEnergyConsumption() = 0;
    virtual double getWaterConsumption() = 0;
    virtual void construct() = 0;
    virtual void demolish() = 0;

    // Additional methods specific to CommercialBuildings
    std::string getBusinessType() const { return businessType; }
    int getNumBusinesses() const { return numBusinesses; }
};

#endif // COMMERCIALBUILDINGS_H
