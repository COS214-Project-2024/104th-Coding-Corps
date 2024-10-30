#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "CityContext.h"
#include "BuildingFactory.h"
#include "Transport.h"
#include "Utilities.h"
#include "Government.h"
#include <memory>
#include <string>

class GameEngine {
private:
    std::shared_ptr<CityContext> cityContext;
    std::unique_ptr<BuildingFactory> buildingFactory;
    std::shared_ptr<Transport> transportSystem;
    std::shared_ptr<Government> government;
    double budget;

public:
    GameEngine();
    void displayIntro();
    void displayMenu();
    void createBuilding(const std::string& type);
    void createUtility(const std::string& type);
    void changeTaxPolicy(double newRate);
    void addTransport(const std::string& type);
    void startSimulation();
    void displayCitySummary();
};

#endif // GAMEENGINE_H
