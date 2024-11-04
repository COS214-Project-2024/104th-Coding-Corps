#ifndef BUILDINGCOMPOSITE_H
#define BUILDINGCOMPOSITE_H

#include "BuildingComponent.h"
#include <vector>
#include <map>
#include <string>
#include <memory> // Include memory for smart pointers

using namespace std;

class BuildingComposite : public BuildingComponent {

private:
	vector<shared_ptr<BuildingComponent>> buildings;
	vector<shared_ptr<Utilities>> utilities;

public:
	BuildingComposite(int x, int y, const std::string& district, int quality);

	std::shared_ptr<BuildingComponent> clone() const override {
		return std::make_shared<BuildingComposite>(*this);
	}
	
	void addBuilding(shared_ptr<BuildingComponent> building);

	void removeBuilding(shared_ptr<BuildingComponent> building);

	shared_ptr<BuildingComponent> getBuilding(int index);

	double getCost() override;

	double getMaintenanceCost() override;

	double getEnergyConsumption() override;

	double getWaterConsumption() override;

	int getBuildingCount() {return buildings.size();};

	std::string getBuildingType() {return "";};
	int getOccupancy() {return 0;};
	void demolish() {};
	void upgrade(std::shared_ptr<BuildingComponent> building) {};
	double getArea() {return 0.0;};
 std::string getType() const override { return "Composite"; }

	std::shared_ptr<BuildingComponent> findBuilding(const std::string& type);

};

#endif
