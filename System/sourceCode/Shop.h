#ifndef SHOP_H
#define SHOP_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;

class Shop : public CommercialBuildings {

private:
	int shopSize;
public:
	Shop(int shopSize, string businessType, int x, int y, const std::string& district, int quality);

    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<Shop>(*this);
    }

	double getCost();

	string getBuildingType();

	double getMaintenanceCost();
std::string getType() const override {
        return "Shop"; // Return the specific type
    }
	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();

	void upgrade(std::shared_ptr<BuildingComponent> building);

	int getOccupancy();
};

#endif
