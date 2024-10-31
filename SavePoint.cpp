#include "SavePoint.h"
#include "Citizen.h"
#include "BuildingComponent.h"
#include "Utilities.h"
#include "Government.h"

SavePoint::SavePoint(int totalPop, double avgStdOfLiving, double avgEduLevel, 
                     double avgIncome, double monthlyExp, int totalBuildings, 
                     int avgBuildingQuality, int totalUtilities,
                     double totalEnergyConsumption, double totalWaterConsumption,
                     double totalEnergyProduction, double totalWaterProduction,
                     std::shared_ptr<Government> governmentState,
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
      government(governmentState),
      population(populationState),
      buildings(buildingsState),
      utilities(utilitiesState) {}

/**
 * @brief Factory method for creating a SavePoint instance.
 */
std::shared_ptr<SavePoint> SavePoint::create(int totalPop, double avgStdOfLiving, double avgEduLevel, 
                                             double avgIncome, double monthlyExp, int totalBuildings, 
                                             int avgBuildingQuality, int totalUtilities,
                                             double totalEnergyConsumption, double totalWaterConsumption,
                                             double totalEnergyProduction, double totalWaterProduction,
                                             std::shared_ptr<Government> governmentState,
                                             const std::map<int, std::shared_ptr<Citizen>>& populationState,
                                             const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
                                             const std::vector<std::shared_ptr<Utilities>>& utilitiesState) {
    return std::shared_ptr<SavePoint>(new SavePoint(totalPop, avgStdOfLiving, avgEduLevel, avgIncome, monthlyExp,
                                                    totalBuildings, avgBuildingQuality, totalUtilities,
                                                    totalEnergyConsumption, totalWaterConsumption, 
                                                    totalEnergyProduction, totalWaterProduction, 
                                                    governmentState, populationState, buildingsState, utilitiesState));
}

/**
 * @brief Retrieves a snapshot of the current state as a SavePoint.
 */
std::shared_ptr<SavePoint> SavePoint::getState() {
    return SavePoint::create(
        totalPopulation,
        averageStandardOfLiving,
        averageEducationLevel,
        averageIncome,
        monthlyExpenditure,
        totalBuildings,
        averageBuildingQuality,
        totalUtilities,
        totalEnergyConsumption,
        totalWaterConsumption,
        totalEnergyProduction,
        totalWaterProduction,
        government,
        population,
        buildings,
        utilities
    );
}

/**
 * @brief Updates the current SavePoint with the state from another SavePoint.
 * 
 * @param savePoint The SavePoint containing the desired state to copy.
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
        government = savePoint->government;
        population = savePoint->population;
        buildings = savePoint->buildings;
        utilities = savePoint->utilities;
    }
}
