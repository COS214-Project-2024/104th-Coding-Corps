#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuildings.h"
#include "string"
using namespace std;
class Office : public CommercialBuildings {

public:
	Office(int numEmployees, string businessType, int x, int y, const std::string& district, int quality);

    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<Office>(*this);
    }

	int numEmployees;

	int getNumEmployees();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();
	std::string getType() const override {
        return "Office"; // Return the specific type
    }

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	double getArea();

	int getOccupancy();
	
	void upgrade(std::shared_ptr<BuildingComponent> building);
};

#endif
