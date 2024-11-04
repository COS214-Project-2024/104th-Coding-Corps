#ifndef SAVEPOINT_H
#define SAVEPOINT_H

#include <vector>
#include <memory>
#include <map>

class CityContext;
class Citizen;
class BuildingComponent;
class Utilities;

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
              double governmentBalance,
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

    // Store balance as a simple variable instead of Government pointer
    double governmentBalance;

    // Deep copies of complex objects
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;
    std::vector<std::shared_ptr<Utilities>> utilities;

public:
    // Factory method to create a SavePoint instance
    static std::shared_ptr<SavePoint> create(int totalPop, double avgStdOfLiving, double avgEduLevel, 
                                             double avgIncome, double monthlyExp, int totalBuildings, 
                                             int avgBuildingQuality, int totalUtilities,
                                             double totalEnergyConsumption, double totalWaterConsumption,
                                             double totalEnergyProduction, double totalWaterProduction,
                                             double governmentBalance,
                                             const std::map<int, std::shared_ptr<Citizen>>& populationState,
                                             const std::vector<std::shared_ptr<BuildingComponent>>& buildingsState,
                                             const std::vector<std::shared_ptr<Utilities>>& utilitiesState);

    // Retrieve a snapshot of the current state
    std::shared_ptr<SavePoint> getState();

    // Restore state from another SavePoint
    void setState(const std::shared_ptr<SavePoint>& savePoint);

    // Accessor for government balance
    double getGovernmentBalance() const { return governmentBalance; }

    // Destructor
    ~SavePoint() = default;

    friend CityContext;
};

#endif // SAVEPOINT_H
