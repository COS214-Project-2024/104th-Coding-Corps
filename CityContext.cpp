#include "CityContext.h"
#include "Citizen.h"
#include <iostream>
#include <algorithm>

/** 
 * @brief Constructs a CityContext.
 */
CityContext::CityContext() : totalPop(0), averageStandardOfLiving(0.0), averageEducationLevel(0.0), averageIncome(0.0) {
    // Constructor implementation
}

/** 
 * @brief Destructor for CityContext.
 */
CityContext::~CityContext() {
    // Destructor implementation
}

//---------------------------------------------------------------------FOR DA CITYZENS--------------------------------------------------------------

/** 
 * @brief Attaches a citizen to the city's population.
 * @param citizen Shared pointer to the citizen to attach.
 */
void CityContext::attach(std::shared_ptr<Citizen> citizen) {
    int id = citizen->getCitizenID();
    population[id] = citizen;
    calculateAverages();
}

/** 
 * @brief Detaches a citizen from the city's population.
 * @param citizen Shared pointer to the citizen to detach.
 */
void CityContext::detach(std::shared_ptr<Citizen> citizen) {
    int id = citizen->getCitizenID();
    population.erase(id);
    calculateAverages();
}

/** 
 * @brief Notifies all citizens of a change in context.
 */
void CityContext::notify() {
    for (auto& [id, citizen] : population) {
        citizen->updateContext();
    }
}


/**
 * @brief Calculates the average standard of living for all citizens in the city.
 * @return double The average standard of living.
 */
double CityContext::calculateAverageStandardOfLiving() {
    if (population.empty()) return 0;
    
    double totalStandardOfLiving = 0;
    for (const auto& [id, citizen] : population) {
        totalStandardOfLiving += citizen->getASoL();
    }
    averageStandardOfLiving = totalStandardOfLiving / population.size();
    return averageStandardOfLiving;
}

/**
 * @brief Calculates the average education level for all citizens in the city.
 * @return double The average education level.
 */
double CityContext::calculateAverageEducationLevel() {
    if (population.empty()) return 0;
    
    double totalEducationLevel = 0;
    for (const auto& [id, citizen] : population) {
        totalEducationLevel += citizen->getEducationLevel();
    }
    averageEducationLevel = totalEducationLevel / population.size();
    return averageEducationLevel;
}

/**
 * @brief Calculates the average income for all citizens in the city.
 * @return double The average income.
 */
double CityContext::calculateAverageIncome() {
    if (population.empty()) return 0;
    
    double totalIncome = 0;
    for (const auto& [id, citizen] : population) {
        totalIncome += citizen->getCurrentIncome();
    }
    averageIncome = totalIncome / population.size();
    return averageIncome;
}

/**
 * @brief Recalculates all average metrics for the city.
 * This includes average standard of living, education level, and income.
 */
void CityContext::calculateAverages() {
    calculateAverageStandardOfLiving();
    calculateAverageEducationLevel();
    calculateAverageIncome();
}


//-----------------------------------------------------FOR DA BUILDINGS----------------------------------------------------------

/**
 * @brief Adds a building to the city's list of buildings.
 * @param building Shared pointer to the building to add.
*/
void CityContext::addBuilding(std::shared_ptr<BuildingComponent> building) {
    buildings.push_back(building);
}

/**
 * @brief Removes a building from the city's list of buildings.
 * @param building Shared pointer to the building to remove.
*/
void CityContext::removeBuilding(std::shared_ptr<BuildingComponent> building) {
    auto it = std::find(buildings.begin(), buildings.end(), building);
    if (it != buildings.end()) {
        buildings.erase(it);
    }
}

//---------------------------------------------------------------FOR DA VIBES!!!!!!!!(im so tired fcking kil me)-------------------------------------------------------------

std::shared_ptr<BuildingComponent> CityContext::findNearestBuilding(const std::shared_ptr<Citizen>& citizen, const std::string& buildingType) {
        
    std::string targetDistrict = citizen->getDistrict();  // Get the citizen's district
    std::shared_ptr<BuildingComponent> nearestBuilding = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (const auto& building : buildings) {
        // Check if building is of the requested type and in the same district
        if (building->getBuildingType() == buildingType) {
            double distance = calculateDistance(citizen->getX(), citizen->getY(),building->getX(), building->getY());
            if (distance < minDistance) {
                minDistance = distance;
                nearestBuilding = building;
                }
            }
        }

        if(nearestBuilding->getDistrict() != targetDistrict){
            citizen->updateSatisfaction(-3); //no building in citizen's district
        }
        else{
            citizen->updateSatisfaction(2);
        }

        citizen->setX(nearestBuilding->getX());
        citizen->setY(nearestBuilding->getY());

        return nearestBuilding;  // Returns nullptr if no building of the specified type is found
}


/**
 * @brief Calculates the Euclidean distance between two points.
 * @param w X-coordinate of the first point.
 * @param x Y-coordinate of the first point.
 * @param y X-coordinate of the second point.
 * @param z Y-coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
double CityContext::calculateDistance(int w, int x, int y, int z) {
    return std::sqrt((y - w)*(y - w) + (z - x)*(z - x));
}