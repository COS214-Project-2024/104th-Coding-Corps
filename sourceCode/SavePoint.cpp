#include "SavePoint.h"
#include "Citizen.h"
#include "BuildingComponent.h"
#include "Utilities.h"

/**
 * @brief Constructs a SavePoint instance with the given state attributes.
 */
SavePoint::SavePoint(int totalPop, double avgStdOfLiving, double avgEduLevel, 
                     double avgIncome, double monthlyExp, int totalBuildings, 
                     int avgBuildingQuality, int totalUtilities,
                     double totalEnergyConsumption, double totalWaterConsumption,
                     double totalEnergyProduction, double totalWaterProduction,
                     double governmentBalance,
                     const std::map<int, std::shared_ptr<Citizen>>& populationState,
                     const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
                     const std::vector<std::shared_ptr<Utilities>>& utilitiesState)
    : totalPopulation(totalPop), 
      averageStandardOfLiving(avgStdOfLiving), 
      averageEducationLevel(avgEduLevel),
      averageIncome(avgIncome),
      monthlyExpenditure(monthlyExp),
      totalBuildings(totalBuildings),
      averageBuildingQuality(avgBuildingQuality),
      totalUtilities(totalUtilities),
      totalEnergyConsumption(totalEnergyConsumption),
      totalWaterConsumption(totalWaterConsumption),
      totalEnergyProduction(totalEnergyProduction),
      totalWaterProduction(totalWaterProduction),
      governmentBalance(governmentBalance) // Store balance instead of Government pointer
{
    // Deep copy of population using clone or copy constructor
    for (const auto& [id, citizen] : populationState) {
        population[id] = std::make_shared<Citizen>(*citizen); // Assume Citizen has a copy constructor
    }

    // Deep copy of buildings using clone or copy constructor
    for (const auto& building : buildingsState) {
        buildings.push_back(building->clone()); // Assume clone() returns a deep copy
    }

    // Deep copy of utilities using clone or copy constructor
    for (const auto& utility : utilitiesState) {
        utilities.push_back(utility->clone()); // Assume clone() returns a deep copy
    }
}

/**
 * @brief Factory method for creating a SavePoint instance.
 */
std::shared_ptr<SavePoint> SavePoint::create(
    int totalPop, double avgStdOfLiving, double avgEduLevel, 
    double avgIncome, double monthlyExp, int totalBuildings, 
    int avgBuildingQuality, int totalUtilities,
    double totalEnergyConsumption, double totalWaterConsumption,
    double totalEnergyProduction, double totalWaterProduction,
    double governmentBalance,
    const std::map<int, std::shared_ptr<Citizen>>& populationState,
    const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
    const std::vector<std::shared_ptr<Utilities>>& utilitiesState
) {
    return std::shared_ptr<SavePoint>(new SavePoint(
        totalPop, avgStdOfLiving, avgEduLevel, avgIncome, monthlyExp,
        totalBuildings, avgBuildingQuality, totalUtilities,
        totalEnergyConsumption, totalWaterConsumption, 
        totalEnergyProduction, totalWaterProduction, 
        governmentBalance, populationState, buildingsState, utilitiesState
    ));
}


/**
 * @brief Updates the current SavePoint with the state from another SavePoint.
 */
void SavePoint::setState(const std::shared_ptr<SavePoint>& savePoint) {
    if (savePoint) {
        totalPopulation = savePoint->totalPopulation;
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
        governmentBalance = savePoint->governmentBalance;

        // Deep copy population
        population.clear();
        for (const auto& [id, citizen] : savePoint->population) {
            population[id] = std::make_shared<Citizen>(*citizen);
        }

        // Deep copy buildings
        buildings.clear();
        for (const auto& building : savePoint->buildings) {
            buildings.push_back(building->clone());
        }

        // Deep copy utilities
        utilities.clear();
        for (const auto& utility : savePoint->utilities) {
            utilities.push_back(utility->clone());
        }
    }
}
