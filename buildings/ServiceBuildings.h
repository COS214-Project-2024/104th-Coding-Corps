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
    ServiceBuildings(int quality, int numWorkers);

    virtual std::string getBuildingType() override;
    virtual int getOccupancy() override;
    virtual double getCost() override;
    virtual double getMaintenanceCost() override;
    virtual double getEnergyConsumption() override;
    virtual double getWaterConsumption() override;
    virtual void demolish() override;
    virtual void upgrade(BuildingComponent* building) override;
    virtual double getArea() override;
    virtual void accept(Citizen* c);
};

#endif
