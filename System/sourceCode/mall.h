#ifndef MALL_H
#define MALL_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;

class Mall : public CommercialBuildings {

private:
	int numShops;
public:
	Mall(int numShops, string businessType, int numBusinesses, int x, int y, const std::string& district, int quality);

    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<Mall>(*this);
    }

	int getNumShops();

	string getBuildingType();

	double getCost();
	std::string getType() const override {
        return "Mall"; // Return the specific type
    }

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();
	
	void upgrade(std::shared_ptr<BuildingComponent> building);

	int getOccupancy();
};

#endif
