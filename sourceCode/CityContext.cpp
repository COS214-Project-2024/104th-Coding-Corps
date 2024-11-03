#include "CityContext.h"
#include "Citizen.h"
#include <iostream>
#include <algorithm>

std::shared_ptr<CityContext> CityContext::instance = nullptr;

/** 
 * @brief Constructs a CityContext with default values.
 */
CityContext::CityContext(std::shared_ptr<Government> government) : totalPop(0), averageStandardOfLiving(0.0), averageEducationLevel(0.0),
            averageIncome(0.0), monthlyExpenditure(0.0), totalBuildings(0),
            averageBuildingQuality(0), totalUtilities(0), government(government){}

/**
 * @brief Returns the singleton instance of CityContext.
 * @return A shared pointer to the single instance of CityContext.
 */
std::shared_ptr<CityContext> CityContext::getInstance(std::shared_ptr<Government> government) {
    if (!instance) {
        instance = std::shared_ptr<CityContext>(new CityContext(government));
    }
    return instance;
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
    auto it = population.find(citizen->getCitizenID());
    if (it == population.end()) {//if not found then add
         int id = citizen->getCitizenID();
        population[id] = citizen;
    calculateAverages();
        }
}
   

/** 
 * @brief Detaches a citizen from the city's population.
 * @param citizen Shared pointer to the citizen to detach.
 */
void CityContext::detach(std::shared_ptr<Citizen> citizen) {
    int id = citizen->getCitizenID();
    std::cout << "Detaching citizen with ID: " << id << std::endl;
    
    if (population.erase(id) > 0) {
        std::cout << "Successfully detached citizen with ID: " << id << std::endl;
    } else {
        std::cout << "Citizen with ID " << id << " not found in population." << std::endl;
    }

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
 * @brief Calculates the total monthly expenditure of all citizens in the city.
 * @return double Total monthly expenditure.
 */
double CityContext::calculateMonthlyExpenditure() {
    if (population.empty()) return 0.0;
    
    double totalExpenditure = 0.0;
    for (const auto& [id, citizen] : population) {
        totalExpenditure += citizen->getCurrentIncome() * 0.7; // Assuming 70% of income as expenditure
    }
    monthlyExpenditure = totalExpenditure;
    return monthlyExpenditure;
}

/**
 * @brief Calculates the average satisfaction level of the city's citizens.
 * @return int Average satisfaction level.
 */
int CityContext::calculateAverageSatisfaction(){
    if (population.empty()) return 0;
    
    int satisfaction = 0;
    for (const auto& [id, citizen] : population) {
        satisfaction += citizen->getSatisfaction();
    }

    averageSatisfaction = satisfaction / population.size();
    return averageSatisfaction;
}

/**
 * @brief Calculates the total population of the city.
 * @return int Total population.
 */
int CityContext::calculateTotalPop(){
    totalPop = population.size();
    return totalPop;
}

const std::map<int, std::shared_ptr<Citizen>>& CityContext::getCitizens() const {
    return population;
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

/**
 * @brief Calculates the total number of buildings in the city.
 * @return int Total number of buildings.
 */
int CityContext::calculateTotalBuildings() {
    totalBuildings = buildings.size();
    return totalBuildings;
}

/**
 * @brief Calculates the average quality of buildings in the city.
 * @return int Average building quality.
 */
int CityContext::calculateAverageBuildingQuality() {
    if (buildings.empty()) return 0;
    
    int totalQuality = 0;
    for (const auto& building : buildings) {
        totalQuality += building->getQuality();
    }
    averageBuildingQuality = totalQuality / buildings.size();
    return averageBuildingQuality;
}

/**
 * @brief Calculates the total energy consumption of all buildings in the city.
 * @return double Total energy consumption.
 */
double CityContext::calculateTotalEnergyConsumption() {
    double totalEnergy = 0.0;
    for (const auto& building : buildings) {
        totalEnergy += building->getEnergyConsumption();
    }
    totalEnergyConsumption = totalEnergy;
    return totalEnergy;
}

/**
 * @brief Calculates the total water consumption of all buildings in the city.
 * @return double Total water consumption.
 */
double CityContext::calculateTotalWaterConsumption() {
    double totalWater = 0.0;
    for (const auto& building : buildings) {
        totalWater += building->getWaterConsumption();
    }
    totalWaterConsumption = totalWater;
    return totalWater;
}

//---------------------------------------------------------------------------FOR DA UTILITIES----------------------------------------------------------------------------------------

/**
 * @brief Calculates the total water production from all water utilities.
 * @return double Total water production.
 */
double CityContext::calculateTotalWaterProduction() {
    double totalWater = 0.0;
    for (const auto& utility : utilities) {
        if (utility->getUtilityType() == "Water Supply") {
            totalWater += utility->getConsumptionRate();  // Assuming consumption rate represents production rate
        }
    }
    totalWaterProduction = totalWater;
    return totalWater;
}

/**
 * @brief Calculates the total energy production from all energy utilities.
 * @return double Total energy production.
 */
double CityContext::calculateTotalEnergyProduction() {
    double totalEnergy = 0.0;
    for (const auto& utility : utilities) {
        if (utility->getUtilityType() == "Power Plant") {
            totalEnergy += utility->getConsumptionRate();  // Assuming consumption rate represents production rate
        }
    }
    totalEnergyProduction = totalEnergy;
    return totalEnergy;
}

/**
 * @brief Counts the total number of utility buildings in the city.
 * @return int Total number of utility buildings.
 */
int CityContext::countTotalUtilities() {
    totalUtilities = utilities.size();
    return totalUtilities;
}

/**
 * @brief Adds a utility to the city's list of utilities.
 * @param utility Shared pointer to the utility to add.
 */
void CityContext::addUtility(std::shared_ptr<Utilities> utility) {
    utilities.push_back(utility);
}

/**
 * @brief Removes a utility from the city's list of utilities.
 * @param utility Shared pointer to the utility to remove.
 */
void CityContext::removeUtility(std::shared_ptr<Utilities> utility) {
    auto it = std::find(utilities.begin(), utilities.end(), utility);
    if (it != utilities.end()) {
        utilities.erase(it);
    }
}

//---------------------------------------------------------------------------FOR SIMULATION------------------------------------------------------------------------------------------

/**
 * @brief Calculates all city-wide averages and totals for a complete summary.
 */
void CityContext::calculateAverages() {
    calculateAverageStandardOfLiving();
    calculateAverageEducationLevel();
    calculateAverageIncome();
    calculateMonthlyExpenditure();
    calculateAverageSatisfaction();
    calculateTotalPop();
    calculateTotalBuildings();
    calculateAverageBuildingQuality();
    calculateTotalEnergyConsumption();
    calculateTotalWaterConsumption();
}

/**
 * @brief Displays a structured summary of the city's citizens, buildings, and utility resources.
 * 
 * This function calculates averages and totals before displaying a formatted
 * city summary in a game-like table format.
 */
void CityContext::getCitySummary() {
    notify(); // Notify first to update citizens' satisfaction
    calculateAverages(); // Calculate averages

    std::cout << "======================= CITY SUMMARY =======================" << std::endl;
    std::cout << "|                        CITIZENS                         |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;
    std::cout << "| Total Population             | " << std::setw(8) << totalPop                  << " citizens      |" << std::endl;
    std::cout << "| Average Satisfaction         | " << std::setw(8) << averageSatisfaction       << "/100           |" << std::endl;
    std::cout << "| Average Education Level      | " << std::setw(8) << averageEducationLevel     << "               |" << std::endl;
    std::cout << "| Average Income               | " << std::setw(8) << averageIncome             << "               |" << std::endl;
    std::cout << "| Average Monthly Expenditure  | " << std::setw(8) << monthlyExpenditure/population.size()        << "               |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;

    std::cout << "\n|                        BUILDINGS                        |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;
    std::cout << "| Total Number of Buildings| " << std::setw(8) << totalBuildings           << " buildings     |" << std::endl;
    std::cout << "| Average Building Quality | " << std::setw(8) << averageBuildingQuality   << "/100           |" << std::endl;
    std::cout << "| Energy Consumption       | " << std::setw(8) << totalEnergyConsumption   << " kWh           |" << std::endl;
    std::cout << "| Water Consumption        | " << std::setw(8) << totalWaterConsumption    << " liters        |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;

    std::cout << "\n|                       UTILITIES                         |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;
    std::cout << "| Total Number of Utilities | " << std::setw(8) << totalUtilities         << " utilities     |" << std::endl;
    std::cout << "| Total Power Generation    | " << std::setw(8) << totalEnergyProduction   << " kWh          |" << std::endl;
    std::cout << "| Total Water Production    | " << std::setw(8) << totalWaterProduction   << " liters        |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;

    // Add Financial and Resource Information
    std::cout << "\n|                       GOVERNMENT                        |" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;
    std::cout << "| City Balance             | " << std::setw(8) << government->getBalance() << " currency units|" << std::endl;
    std::cout << "|--------------------------------------------------------|" << std::endl;

    // Display additional city resources from the government
    government->displayCityResources();

    std::cout << "==========================================================" << std::endl;
}

//----------------------------------------------------------------MEMENTO TINGS YERRR----------------------------------------------------------------

std::shared_ptr<SavePoint> CityContext::saveGame() {
    return std::shared_ptr<SavePoint>(new SavePoint(
        totalPop, averageStandardOfLiving, averageEducationLevel,
        averageIncome, monthlyExpenditure, totalBuildings, 
        averageBuildingQuality, totalUtilities, totalEnergyConsumption,
        totalWaterConsumption, totalEnergyProduction, totalWaterProduction,
        government, population, buildings, utilities));
}

void CityContext::setSavePoint(std::shared_ptr<SavePoint> savePoint) {
    if (savePoint) {
        // Restore each member of CityContext from the SavePoint
        totalPop = savePoint->totalPopulation;
        averageStandardOfLiving = savePoint->averageStandardOfLiving;
        averageEducationLevel = savePoint->averageEducationLevel;
        averageIncome = savePoint->averageIncome;
        monthlyExpenditure = savePoint->monthlyExpenditure;
        totalBuildings = savePoint->totalBuildings;
        averageBuildingQuality = savePoint->averageBuildingQuality;
        totalUtilities = savePoint->totalUtilities;
        totalEnergyConsumption = savePoint->totalEnergyConsumption;
        totalWaterConsumption = savePoint->totalWaterConsumption;
        totalEnergyProduction = savePoint->totalEnergyProduction;
        totalWaterProduction = savePoint->totalWaterProduction;

        // Restore complex objects
        government = savePoint->government;
        population = savePoint->population;
        buildings = savePoint->buildings;
        utilities = savePoint->utilities;
    }
}





//---------------------------------------------------------------FOR DA VIBES------------------------------------------------------------------------

/**
 * @brief Finds the nearest building of a specified type to a given citizen.
 * @param citizen Shared pointer to the citizen looking for the building.
 * @param buildingType Type of building to search for (e.g., "House", "Shop").
 * @return Shared pointer to the nearest building of the specified type.
 */
std::shared_ptr<BuildingComponent> CityContext::findNearestBuilding(int citizenID, const std::string& buildingType) {
    // Retrieve the citizen from the population map using citizenID
    auto it = population.find(citizenID);
    if (it == population.end()) {
        std::cerr << "Citizen with ID " << citizenID << " not found." << std::endl;
        return nullptr;  // Return nullptr if citizen is not found
    }

    auto citizen = it->second;  // Get the citizen object
    std::string targetDistrict = citizen->getDistrict();  // Get the citizen's district
    std::shared_ptr<BuildingComponent> nearestBuilding = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (const auto& building : buildings) {
        // Check if building is of the requested type and in the same district
        if (building->getBuildingType() == buildingType) {
            double distance = calculateDistance(citizen->getX(), citizen->getY(), building->getX(), building->getY());
            if (distance < minDistance) {
                minDistance = distance;
                nearestBuilding = building;
            }
        }
    }

    // Update citizen's satisfaction and location based on nearest building found
    if (nearestBuilding) {
        if (nearestBuilding->getDistrict() != targetDistrict) {
            citizen->updateSatisfaction(-3); // No building in citizen's district
        } else {
            citizen->updateSatisfaction(2);
        }

        if(citizen->getDistrict() == "-"){
            citizen->setDistrict(nearestBuilding->getDistrict());
        }

        citizen->setX(nearestBuilding->getX());
        citizen->setY(nearestBuilding->getY());
    }

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


/**
 * @brief Enforces a policy by updating its value if valid.
 * 
 * @param policyKey The key of the policy to update.
 * @param newValue The new value for the policy.
 */
void CityContext::enforcePolicy(const std::string& policyKey, const std::string& newValue) {
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
 * @brief Retrieves the current value of a specific policy.
 * 
 * @param policyKey The key of the policy to retrieve.
 * @return The current value of the policy if it exists; an empty string if not found.
 */
std::string CityContext::getPolicyValue(const std::string& policyKey) const {
    auto it = policies.find(policyKey);
    if (it != policies.end()) {
        return it->second;  // Return the current value of the policy if found
    } else {
        std::cerr << "Policy '" << policyKey << "' not found." << std::endl;
        return "";  // Return an empty string if the policy is not found
    }
}


//for testing:
void CityContext::reset() {
    buildings.clear();
    population.clear();
    utilities.clear();
    totalUtilities = 0;
    totalBuildings = 0;
    totalPop = 0;
}
