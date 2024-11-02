#include "SavePoint.h"
#include "Citizen.h"
#include "BuildingComponent.h"
#include "Utilities.h"
#include "Government.h"

/**
 * @brief Constructs a SavePoint instance with the given state attributes.
 * 
 * This constructor initializes a SavePoint object that captures the current 
 * state of the simulation, including population metrics, building statistics, 
 * utility information, and government state.
 * 
 * @param totalPop Total population in the simulation.
 * @param avgStdOfLiving Average standard of living.
 * @param avgEduLevel Average education level.
 * @param avgIncome Average income.
 * @param monthlyExp Monthly expenditure.
 * @param totalBuildings Total number of buildings.
 * @param avgBuildingQuality Average quality of buildings.
 * @param totalUtilities Total number of utilities.
 * @param totalEnergyConsumption Total energy consumption.
 * @param totalWaterConsumption Total water consumption.
 * @param totalEnergyProduction Total energy production.
 * @param totalWaterProduction Total water production.
 * @param governmentState Shared pointer to the government state.
 * @param populationState Map containing citizens in the population state.
 * @param buildingsState Vector containing building components in the state.
 * @param utilitiesState Vector containing utilities in the state.
 */
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
 * 
 * This method creates a new shared pointer to a SavePoint instance, 
 * encapsulating the provided state parameters.
 * 
 * @param totalPop Total population in the simulation.
 * @param avgStdOfLiving Average standard of living.
 * @param avgEduLevel Average education level.
 * @param avgIncome Average income.
 * @param monthlyExp Monthly expenditure.
 * @param totalBuildings Total number of buildings.
 * @param avgBuildingQuality Average quality of buildings.
 * @param totalUtilities Total number of utilities.
 * @param totalEnergyConsumption Total energy consumption.
 * @param totalWaterConsumption Total water consumption.
 * @param totalEnergyProduction Total energy production.
 * @param totalWaterProduction Total water production.
 * @param governmentState Shared pointer to the government state.
 * @param populationState Map containing citizens in the population state.
 * @param buildingsState Vector containing building components in the state.
 * @param utilitiesState Vector containing utilities in the state.
 * @return A shared pointer to the newly created SavePoint.
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
 * 
 * This method returns a new shared pointer to a SavePoint that captures 
 * the current state of the simulation.
 * 
 * @return A shared pointer to the current state as a SavePoint.
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
 * This method copies the state attributes from the provided SavePoint into 
 * the current instance.
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
