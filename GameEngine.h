#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "source code/CityContext.h"
#include "source code/BuildingFactory.h"
#include "source code/Transport.h"
#include "source code/Utilities.h"
#include "source code/Government.h"
#include "source code/BuildingComponent.h"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

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
    void createBuilding(const std::string& type, std::string district);
    void createUtility(const std::string& type);
    void changeTaxPolicy(double newRate);
    void addTransport(const std::string& type);
    void startSimulation();
    void displayCitySummary();
};

#endif // GAMEENGINE_H
