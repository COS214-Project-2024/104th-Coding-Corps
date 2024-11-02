#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "source code/CityContext.h"
#include "source code/BuildingFactory.h"
#include "source code/BuildingComposite.h"
#include "source code/Transport.h"
#include "source code/Utilities.h"
#include "source code/Government.h"
#include "source code/BuildingComponent.h"
#include "source code/PowerPlantFactory.h"
#include "source code/WaterSupplyFactory.h"
#include "source code/SewageSystemFactory.h"
#include "source code/WasteManagementFactory.h"
#include "source code/PolicyCommand.h"
#include "source code/Command.h"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

class GameEngine {
private:
    std::shared_ptr<CityContext> cityContext;
    std::shared_ptr<BuildingFactory> buildingFactory;
    std::shared_ptr<Transport> transportSystem;
    std::shared_ptr<Government> government;
    std::vector<std::shared_ptr<AbstractCitizen>> citizens;
    double budget;

    std::vector<std::string> districts; 
    std::shared_ptr<BuildingComposite> currentComposite;
    std::vector<std::shared_ptr<BuildingComposite>> buildingComposites;
    int currentBuildingCount = 0;
    int currentDistrictIndex = 0; 


public:
    GameEngine();
    void displayIntro();
    void displayMenu();
    void createBuilding(const std::string& type);
    void createUtility(const std::string& type);
    void changeTaxPolicy();
    void createCitizens(int n);
    void startSimulation();
    void displayCitySummary();
    void viewGamIndex();
};

#endif // GAMEENGINE_H
