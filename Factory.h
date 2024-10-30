#ifndef FACTORY_H
#define FACTORY_H

#include "IndustrialBuildings.h"
#include <string>

class Factory : public IndustrialBuildings {

public:

    Factory(int numWorkers, string factoryType, double production);

    void produceGoods();

    std::string getBuildingType();

    std::string getFactoryType();

    int getOccupancy();

    double getCost();

    double getMaintenanceCost();

    double getEnergyConsumption();

    double getWaterConsumption();

    void construct();

    void demolish();

    void upgrade(BuildingComponent* building) override;

    double getArea();

private:
    string factoryType;
};

#endif
