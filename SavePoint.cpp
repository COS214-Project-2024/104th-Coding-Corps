#include "SavePoint.h"
#include "Citizen.h"
#include "BuildingComponent.h"
#include "Utilities.h"
#include "Government.h"

/**
 * @brief Constructs a SavePoint that stores a snapshot of CityContext's state.
 * 
 * @param totalPop Total population in the city.
 * @param avgStdOfLiving Average standard of living for the city.
 * @param avgEduLevel Average education level of the citizens.
 * @param avgIncome Average income of the citizens.
 * @param monthlyExp Total monthly expenditure for the city.
 * @param totalBuildings Total number of buildings in the city.
 * @param avgBuildingQuality Average quality rating of the buildings.
 * @param totalUtilities Total number of utilities in the city.
 * @param totalEnergyConsumption Total energy consumption of the city.
 * @param totalWaterConsumption Total water consumption of the city.
 * @param totalEnergyProduction Total energy production of the city.
 * @param totalWaterProduction Total water production of the city.
 * @param governmentState Shared pointer to the current government state.
 * @param populationState Map of citizen IDs to their respective shared pointers.
 * @param buildingsState Vector of shared pointers to buildings.
 * @param utilitiesState Vector of shared pointers to utilities.
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
      utilities(utilitiesState) {} //look at this teeny tiny constructor body that's so silly
//Ehhhhhhhh  :0 that's so crazy man

std::shared_ptr<SavePoint> SavePoint::getState() {
    // Creates a SavePoint containing the current state of CityContext
    return std::make_shared<SavePoint>(
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
        government,         // Assuming government is a shared_ptr to the Government class
        population,         // Map of citizens
        buildings,          // Vector of buildings
        utilities           // Vector of utilities
    );
}


/**
 * @brief Updates the current SavePoint with the state from another SavePoint.
 * 
 * @param savePoint The SavePoint containing the desired state to copy.
 */
void SavePoint::setState(std::shared_ptr<SavePoint> savePoint) {
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