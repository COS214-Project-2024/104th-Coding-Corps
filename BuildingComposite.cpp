#include "BuildingComposite.h"
#include <algorithm>
#include <iostream>

// Constructor (if any initialization is needed)
BuildingComposite::BuildingComposite(int x, int y, const std::string& district, int quality) : BuildingComponent( x, y, district,  quality) {}

// Add a building to the composite
void BuildingComposite::addBuilding(shared_ptr<BuildingComponent> building) {
    buildings.push_back(building);
}

// Remove a building from the composite
void BuildingComposite::removeBuilding(shared_ptr<BuildingComponent> building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

// Get a building from the composite by index
shared_ptr<BuildingComponent> BuildingComposite::getBuilding(int index) {
    if (index >= 0 && index < buildings.size()) {
        return buildings[index];
    }
    return nullptr; // or handle error as needed
}

// Calculate the total cost of all buildings in the composite
double BuildingComposite::getCost() {
    double totalCost = 0.0;
    for (const auto& building : buildings) {
        totalCost += building->getCost(); // Assuming getCost() is defined in BuildingComponent
    }
    return totalCost;
}

// Calculate the total energy consumption of all buildings in the composite
double BuildingComposite::getEnergyConsumption() {
    double totalEnergy = 0.0;
    for (const auto& building : buildings) {
        totalEnergy += building->getEnergyConsumption(); // Assuming getEnergyConsumption() is defined
    }
    return totalEnergy;
}

// Calculate the total water consumption of all buildings in the composite
double BuildingComposite::getWaterConsumption() {
    double totalWater = 0.0;
    for (const auto& building : buildings) {
        totalWater += building->getWaterConsumption(); // Assuming getWaterConsumption() is defined
    }
    return totalWater;
}

void BuildingComposite::enforcePolicy(const std::string& policyKey, const std::string& newValue) {
    // Check if the policyKey exists in the policies map
    auto it = policies.find(policyKey);
    if (it != policies.end()) {
        // Validate the newValue against allowed values
        auto allowedIt = allowedValues.find(policyKey);
        if (allowedIt != allowedValues.end()) {
            const auto& allowedOptions = allowedIt->second;
            if (std::find(allowedOptions.begin(), allowedOptions.end(), newValue) != allowedOptions.end()) {
                // Update the policy if newValue is valid
                it->second = newValue;
                std::cout << "Policy '" << policyKey << "' updated to: " << newValue << std::endl;
            } else {
                // Invalid newValue for the policy
                std::cerr << "Invalid value '" << newValue << "' for policy '" << policyKey << "'. Update failed." << std::endl;
            }
        } else {
            // Policy key has no allowed values defined
            std::cerr << "Policy '" << policyKey << "' has no predefined allowed values. Update failed." << std::endl;
        }
    } else {
        // Policy key not found in existing policies
        std::cerr << "Policy '" << policyKey << "' not found. Update failed." << std::endl;
    }
}

// Calculate the total maintenance cost of all buildings in the composite
double BuildingComposite::getMaintenanceCost() {
    double totalMaintenanceCost = 0.0;
    for (const auto& building : buildings) {
        totalMaintenanceCost += building->getMaintenanceCost(); // Each building implements this
    }
    return totalMaintenanceCost;
}


