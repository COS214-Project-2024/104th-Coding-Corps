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
std::shared_ptr<BuildingComponent> BuildingComposite::getBuilding(int index) {
    if (index >= 0 && index < static_cast<int>(buildings.size())) {
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


/**
 * @brief Finds a building in the composite by its type.
 * 
 * @param type The type of the building to find (as a string).
 * @return A shared pointer to the BuildingComponent if found, nullptr otherwise.
 */
std::shared_ptr<BuildingComponent> BuildingComposite::findBuilding(const std::string& type) {
    std::shared_ptr<BuildingComponent> building = nullptr;

    for (const auto& building1 : buildings) {
        if (building1 && building1->getType() == type) { // Ensure building1 is not nullptr
            if (building1->getQuality() <= 50) {
                // Return the first non-upgraded building found
                return building1;
            }
            // Store the first upgraded building if no non-upgraded ones are found
            if (!building) {
                building = building1;
            }
        }
    }

    return building;
}
