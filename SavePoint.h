#ifndef SAVEPOINT_H
#define SAVEPOINT_H

#include <vector>
#include <memory>
#include <map>

class CityContext;
class Citizen;
class BuildingComponent;
class Utilities;
class Government;

/**
 * @brief Memento class to save and restore CityContext's state.
 */
class SavePoint {
private:
    // Private constructor to restrict access only to CityContext
    SavePoint(int totalPop, double avgStdOfLiving, double avgEduLevel, 
              double avgIncome, double monthlyExp, int totalBuildings, 
              int avgBuildingQuality, int totalUtilities,
              double totalEnergyConsumption, double totalWaterConsumption,
              double totalEnergyProduction, double totalWaterProduction,
              std::shared_ptr<Government> governmentState,
              const std::map<int, std::shared_ptr<Citizen>>& populationState,
              const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
              const std::vector<std::shared_ptr<Utilities>>& utilitiesState);
    
    std::shared_ptr<SavePoint> getState();
    void setState(std::shared_ptr<SavePoint> savePoint);

    // State variables that need to be saved
    int totalPopulation;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    double monthlyExpenditure;
    int totalBuildings;
    int averageBuildingQuality;
    int totalUtilities;

    // Additional state for energy and water
    double totalEnergyConsumption;
    double totalWaterConsumption;
    double totalEnergyProduction;
    double totalWaterProduction;

    // Other member objects to capture full state
    std::shared_ptr<Government> government;
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;
    std::vector<std::shared_ptr<Utilities>> utilities;

    friend class CityContext; // Only CityContext can create and use SavePoint

public:
    ~SavePoint() = default;
};

#endif // SAVEPOINT_H
