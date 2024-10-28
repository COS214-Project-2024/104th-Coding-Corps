#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

//#include "Citizen.h"
#include <map>
#include <memory>

class Citizen;

class CityContext {
private:
    double GDP;
    int totalPop;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    std::map<int, std::shared_ptr<Citizen>> population;
    std::vector<std::shared_ptr<BuildingComponent>> buildings;

public:
    CityContext();
    ~CityContext();

    void attach(std::shared_ptr<Citizen> citizen);
    void detach(std::shared_ptr<Citizen> citizen);
    void notify();

    double calculateAverageStandardOfLiving();
    double calculateAverageEducationLevel();
    double calculateAverageIncome();
    void calculateAverages();
};

#endif // CITYCONTEXT_H
