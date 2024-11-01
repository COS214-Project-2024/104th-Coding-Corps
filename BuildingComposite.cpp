#include "BuildingComposite.h"
#include <algorithm>
#include <iostream>

/**
 * @brief Constructs a BuildingComposite with specified parameters.
 * 
 * @param x The x-coordinate of the composite building.
 * @param y The y-coordinate of the composite building.
 * @param district The district where the composite building is located.
 * @param quality The quality rating of the composite building.
 */
BuildingComposite::BuildingComposite(int x, int y, const std::string& district, int quality) 
    : BuildingComponent(x, y, district, quality) {}

/**
 * @brief Adds a building to the composite.
 * 
 * @param building A shared pointer to the BuildingComponent to add.
 */
void BuildingComposite::addBuilding(shared_ptr<BuildingComponent> building) {
    buildings.push_back(building);
}

/**
 * @brief Removes a building from the composite.
 * 
 * @param building A shared pointer to the BuildingComponent to remove.
 */
void BuildingComposite::removeBuilding(shared_ptr<BuildingComponent> building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

/**
 * @brief Gets a building from the composite by index.
 * 
 * @param index The index of the building to retrieve.
 * @return A shared pointer to the BuildingComponent at the specified index, or nullptr if the index is invalid.
 */
shared_ptr<BuildingComponent> BuildingComposite::getBuilding(int index) {
    if (index >= 0 && index < buildings.size()) {
        return buildings[index];
    }
    return nullptr; // or handle error as needed
}

/**
 * @brief Calculates the total cost of all buildings in the composite.
 * 
 * @return The total cost of all buildings.
 */
double BuildingComposite::getCost() {
    double totalCost = 0.0;
    for (const auto& building : buildings) {
        totalCost += building->getCost(); // Assuming getCost() is defined in BuildingComponent
    }
    return totalCost;
}

/**
 * @brief Calculates the total energy consumption of all buildings in the composite.
 * 
 * @return The total energy consumption of all buildings.
 */
double BuildingComposite::getEnergyConsumption() {
    double totalEnergy = 0.0;
    for (const auto& building : buildings) {
        totalEnergy += building->getEnergyConsumption(); // Assuming getEnergyConsumption() is defined
    }
    return totalEnergy;
}

/**
 * @brief Calculates the total water consumption of all buildings in the composite.
 * 
 * @return The total water consumption of all buildings.
 */
double BuildingComposite::getWaterConsumption() {
    double totalWater = 0.0;
    for (const auto& building : buildings) {
        totalWater += building->getWaterConsumption(); // Assuming getWaterConsumption() is defined
    }
    return totalWater;
}

/**
 * @brief Enforces a policy by updating its value if valid.
 * 
 * @param policyKey The key of the policy to update.
 * @param newValue The new value for the policy.
 */
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

/**
 * @brief Calculates the total maintenance cost of all buildings in the composite.
 * 
 * @return The total maintenance cost of all buildings.
 */
double BuildingComposite::getMaintenanceCost() {
    double totalMaintenanceCost = 0.0;
    for (const auto& building : buildings) {
        totalMaintenanceCost += building->getMaintenanceCost(); // Each building implements this
    }
    return totalMaintenanceCost;
}
