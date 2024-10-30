#include "BuildingComposite.h"
#include <algorithm>

// Constructor (if any initialization is needed)
BuildingComposite::BuildingComposite() {}

// Add a building to the composite
void BuildingComposite::addBuilding(BuildingComponent* building) {
    buildings.push_back(building);
}

// Remove a building from the composite
void BuildingComposite::removeBuilding(BuildingComponent* building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

// Get a building from the composite by index
BuildingComponent* BuildingComposite::getBuilding(int index) {
    if (index >= 0 && index < buildings.size()) {
        return buildings[index];
    }
    return nullptr; // or handle error as needed
}

// Calculate the total cost of all buildings in the composite
double BuildingComposite::calculateTotalCost() {
    double totalCost = 0.0;
    for (const auto& building : buildings) {
        totalCost += building->getCost(); // Assuming getCost() is defined in BuildingComponent
    }
    return totalCost;
}

// Calculate the total energy consumption of all buildings in the composite
double BuildingComposite::calculateTotalEnergyConsumption() {
    double totalEnergy = 0.0;
    for (const auto& building : buildings) {
        totalEnergy += building->getEnergyConsumption(); // Assuming getEnergyConsumption() is defined
    }
    return totalEnergy;
}

// Calculate the total water consumption of all buildings in the composite
double BuildingComposite::calculateTotalWaterConsumption() {
    double totalWater = 0.0;
    for (const auto& building : buildings) {
        totalWater += building->getWaterConsumption(); // Assuming getWaterConsumption() is defined
    }
    return totalWater;
}

void BuildingComposite::enforcePolicy(string policy){
    //implement
}
