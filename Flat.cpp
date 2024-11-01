#include "Flat.h"
#include <stdexcept>

/**
 * @brief Constructs a Flat object with specified parameters.
 * 
 * Initializes a Flat with the given coordinates, district, quality, 
 * number of units, number of residents, number of floors, and garden availability.
 * 
 * @param x The x-coordinate of the flat.
 * @param y The y-coordinate of the flat.
 * @param district The district where the flat is located.
 * @param quality The quality rating of the flat.
 * @param units The number of units in the flat.
 * @param residents The number of residents in the flat.
 * @param floors The number of floors in the flat.
 * @param hasGarden Whether the flat has a garden.
 */
Flat::Flat(int x, int y, const std::string& district, int quality, int units, int residents, int floors, bool hasGarden)
    : ResidentialBuildings(x, y, district, quality, residents, floors, hasGarden), numUnits(units) {}

/**
 * @brief Gets the number of units in the flat.
 * 
 * @return The number of units in the flat.
 */
int Flat::getNumUnits() const {
    return numUnits;
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the building type "Flat".
 */
std::string Flat::getBuildingType() {
    return "Flat";
}

/**
 * @brief Calculates the cost of the flat.
 * 
 * @return The total cost of the flat, which is a constant value.
 */
double Flat::getCost() {
    return 1595000.00; // Constant cost for a flat
}

/**
 * @brief Calculates the maintenance cost of the flat.
 * 
 * @return The maintenance cost, calculated as a percentage of the total cost.
 */
double Flat::getMaintenanceCost() {
    return 0.02 * getCost(); // Maintenance cost is 2% of the cost
}

/**
 * @brief Calculates the total energy consumption of the flat.
 * 
 * @return The total energy consumption based on the number of units.
 */
double Flat::getEnergyConsumption() {
    const double energyPerUnit = 300.0; // Energy consumption per unit
    return energyPerUnit * this->numUnits;
}

/**
 * @brief Calculates the total water consumption of the flat.
 * 
 * @return The total water consumption based on the number of units.
 */
double Flat::getWaterConsumption() {
    const double waterPerUnit = 2500.0; // Water consumption per unit
    return waterPerUnit * this->numUnits;
}

/**
 * @brief Demolishes the flat by resetting its attributes.
 * 
 * This function resets the number of residents, floors, and units 
 * to simulate the demolition of the flat.
 */
void Flat::demolish() {
    this->numResidents = 0;
    this->numFloors = 0;
    this->numUnits = 0;
}

/**
 * @brief Gets the total number of residents in the flat.
 * 
 * @return The total number of residents, calculated as three times the number of units.
 */
int Flat::getNumResidents() {
    return this->numUnits * 3; // Assuming each unit houses 3 residents
}

/**
 * @brief Calculates the total area of the flat.
 * 
 * @return The total area of the flat, calculated as the product of dimensions and number of units.
 */
double Flat::getArea() {
    return getX() * getY() * this->numUnits; // Area for each unit
}

/**
 * @brief Gets the occupancy of the flat.
 * 
 * @return The number of units in the flat.
 */
int Flat::getOccupancy() {
    return numUnits;
}

/**
 * @brief Upgrades the flat if sufficient resources are available.
 * 
 * This function requests resources from the Government and, if available,
 * increases the quality of the flat. If resources are insufficient, it 
 * indicates the upgrade failed.
 * 
 * @param building A shared pointer to a BuildingComponent (not used in this implementation).
 */
void Flat::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 200;
    const int requiredSteel = 100;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10;  // Example improvement in quality
        std::cout << "Flat upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}
