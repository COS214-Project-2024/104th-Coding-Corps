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
	std::map<std::string, std::vector<std::string>> allowedValues = {
    {"Maximum number of power plants", {"1", "2", "3"}},
    {"Waste removal frequency", {"weekly", "bi-weekly", "monthly"}},
    {"Maximum number of buildings per district", {"100", "200", "300", "400", "500"}},
    {"Renewable energy target", {"0%", "20%", "40%", "60%", "80%", "100%"}},
    {"Police patrol frequency", {"low", "medium", "high"}},
    {"School capacity limit", {"100", "250", "500", "750", "1000"}},
    {"tax rate", {"low", "standard", "high"}}
	};
	std::map<std::string, std::string> policies = {
    {"Maximum number of power plants", "1"}, //1-3
    {"Waste removal frequency", "bi-weekly"}, //weekly, bi-weekly, monthly
    {"Maximum number of buildings per district", "100"}, //1 - 500
    {"Renewable energy target", "40%"}, //0% - 100%
    {"Police patrol frequency", "high"}, //low, medium, high
    {"School capacity limit", "500"}, //100-1000
    {"tax rate", "standard"}, //low, standard, high
	};

public:
	BuildingComposite(int x, int y, const std::string& district, int quality);
	
	void addBuilding(shared_ptr<BuildingComponent> building) override;

	void removeBuilding(shared_ptr<BuildingComponent> building) override;

	shared_ptr<BuildingComponent> getBuilding(int index) override;

	double getCost() override;

	double getMaintenanceCost() override;

	double getEnergyConsumption() override;

	double getWaterConsumption() override;

	void enforcePolicy(const std::string& policyKey, const std::string& newValue) override;
};

#endif
