#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

#include "Citizen.h"
#include "BuildingComponent.h"
#include <map>
#include <memory>

class Citizen;

class CityContext {
private:
    int totalPop;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    double monthlyExpenditure;
    int totalBuildings;
    int averageBuildingQuality;
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;

public:
    CityContext();
    ~CityContext();

    void attach(std::shared_ptr<Citizen> citizen);
    void detach(std::shared_ptr<Citizen> citizen);
    void notify();

    void removeBuilding(std::shared_ptr<BuildingComponent> building);
    void addBuilding(std::shared_ptr<BuildingComponent> building);

    double calculateAverageStandardOfLiving();
    double calculateAverageEducationLevel();
    double calculateAverageIncome();
    void calculateAverages();
    std::shared_ptr<BuildingComponent> findNearestBuilding(const std::shared_ptr<Citizen>& citizen, const std::string& buildingType);
    double calculateDistance(int x1, int y1, int x2, int y2);
};

#endif // CITYCONTEXT_H
