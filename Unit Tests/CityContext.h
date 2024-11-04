#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

#include "Citizen.h"
#include "BuildingComponent.h"
#include "Utilities.h"
#include "SavePoint.h"
#include <map>
#include <memory>

class Citizen;

class CityContext {
private:
    static std::shared_ptr<CityContext> instance;
    int totalPop;
    int averageSatisfaction;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    double monthlyExpenditure;
    int totalBuildings;
    int averageBuildingQuality;
    int totalUtilities;
    double totalEnergyConsumption;
    double totalWaterConsumption;
    double totalWaterProduction;
    double totalEnergyProduction;
    double totalMaintenanceCost; // this needs to be subtracted from the budget at the end of every round
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;
    std::vector<std::shared_ptr<Utilities>> utilities;
    std::shared_ptr<Government> government;           

    CityContext();
    CityContext(const CityContext&) = delete;
    CityContext& operator=(const CityContext&) = delete;

	std::map<std::string, std::vector<std::string>> allowedValues = {
    {"Maximum number of power plants", {"1", "2", "3"}},
    {"Waste removal frequency", {"weekly", "bi-weekly", "monthly"}}, //add reactions
    {"Maximum number of buildings per district", {"100", "200", "300", "400", "500"}},
    {"Renewable energy target", {"0%", "20%", "40%", "60%", "80%", "100%"}},
    {"Police patrol frequency", {"low", "medium", "high"}}, //add reactions
    {"School capacity limit", {"100", "250", "500", "750", "1000"}},
    {"tax rate", {"low", "standard", "high"}}
	};
	std::map<std::string, std::string> policies = {
    {"Maximum number of power plants", "1"}, //1-3
    {"Waste removal frequency", "bi-weekly"}, //weekly, bi-weekly, monthly
    {"Maximum number of buildings per district", "100"}, //1 - 500
    {"Renewable energy target", "40%"}, //0% - 100%
    {"Police patrol frequency", "medium"}, //low, medium, high
    {"School capacity limit", "500"}, //100-1000
    {"tax rate", "standard"}, //low, standard, high
	};

public:
//Singleton Pattern
    static std::shared_ptr<CityContext> getInstance();
    ~CityContext();

//Citizen functions
    void attach(std::shared_ptr<Citizen> citizen);
    void detach(std::shared_ptr<Citizen> citizen);
    void notify();
    int calculateAverageSatisfaction();
    double calculateAverageStandardOfLiving();
    double calculateAverageEducationLevel();
    double calculateAverageIncome();
    int calculateTotalPop();
    double calculateMonthlyExpenditure();
    const std::map<int, std::shared_ptr<Citizen>>& getCitizens() const;


//Building Functions
    void removeBuilding(std::shared_ptr<BuildingComponent> building);
    void addBuilding(std::shared_ptr<BuildingComponent> building);
    int calculateTotalBuildings();
    int calculateAverageBuildingQuality();
    double calculateTotalEnergyConsumption();
    double calculateTotalWaterConsumption();
    double getTotalMaintenanceCost();

//Utility Functions
    void addUtility(std::shared_ptr<Utilities> utility);
    void removeUtility(std::shared_ptr<Utilities> utility);
    double calculateTotalWaterProduction();
    double calculateTotalEnergyProduction();
    int countTotalUtilities();

//Simulation Functions
    void calculateAverages();
    void getCitySummary();

//Memento Functions
    std::shared_ptr<SavePoint> saveGame(); //createMemento
    void setSavePoint(std::shared_ptr<SavePoint> savePoint); //setMemento


//Other
    std::shared_ptr<BuildingComponent> findNearestBuilding(int citizenID, const std::string& buildingType);
    double calculateDistance(int x1, int y1, int x2, int y2);
	void enforcePolicy(const std::string& policyKey, const std::string& newValue);
    std::string getPolicyValue(const std::string& policyKey) const;
    void reset();
};

#endif // CITYCONTEXT_H
