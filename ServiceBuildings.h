#ifndef SERVICEBUILDINGS_H
#define SERVICEBUILDINGS_H

#include "BuildingComponent.h"
#include "Citizen.h"
#include <string>

class ServiceBuildings : public BuildingComponent {
protected:
    int quality;
    int numWorkers;

public:
    ServiceBuildings(int quality, int numWorkers){
        this->quality = quality;
        this->numWorkers = numWorkers;
    }

    virtual std::string getBuildingType() override = 0;
    virtual int getOccupancy() override = 0;
    virtual double getCost() override = 0;
    virtual double getMaintenanceCost() override = 0;
    virtual double getEnergyConsumption() override = 0;
    virtual double getWaterConsumption() override = 0;
    virtual void upgrade(BuildingComponent* building) override = 0;
    virtual double getArea() override = 0;
    virtual void accept(Citizen* c) = 0;
};

#endif
