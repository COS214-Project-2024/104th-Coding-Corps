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
class SavePoint : public std::enable_shared_from_this<SavePoint> {
private:
    // Private constructor, accessible only within this class
    SavePoint(int totalPop, double avgStdOfLiving, double avgEduLevel, 
              double avgIncome, double monthlyExp, int totalBuildings, 
              int avgBuildingQuality, int totalUtilities,
              double totalEnergyConsumption, double totalWaterConsumption,
              double totalEnergyProduction, double totalWaterProduction,
              std::shared_ptr<Government> governmentState,
              const std::map<int, std::shared_ptr<Citizen>>& populationState,
              const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
              const std::vector<std::shared_ptr<Utilities>>& utilitiesState);

    // State variables to be saved
    int totalPopulation;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    double monthlyExpenditure;
    int totalBuildings;
    int averageBuildingQuality;
    int totalUtilities;
    double totalEnergyConsumption;
    double totalWaterConsumption;
    double totalEnergyProduction;
    double totalWaterProduction;

    std::shared_ptr<Government> government;
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;
    std::vector<std::shared_ptr<Utilities>> utilities;

    // Private methods for state management, accessible only by CityContext
    std::shared_ptr<SavePoint> getState();
    void setState(const std::shared_ptr<SavePoint>& savePoint);

    friend class CityContext; // CityContext can access all members

public:
    static std::shared_ptr<SavePoint> create(int totalPop, double avgStdOfLiving, double avgEduLevel, 
                                             double avgIncome, double monthlyExp, int totalBuildings, 
                                             int avgBuildingQuality, int totalUtilities,
                                             double totalEnergyConsumption, double totalWaterConsumption,
                                             double totalEnergyProduction, double totalWaterProduction,
                                             std::shared_ptr<Government> governmentState,
                                             const std::map<int, std::shared_ptr<Citizen>>& populationState,
                                             const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
                                             const std::vector<std::shared_ptr<Utilities>>& utilitiesState);

    ~SavePoint() = default;
};

#endif // SAVEPOINT_H
