#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "sourceCode/CityContext.h"
#include "sourceCode/BuildingFactory.h"
#include "sourceCode/ResidentialBuildingFactory.h"
#include "sourceCode/CommercialBuildingFactory.h"
#include "sourceCode/ServiceBuildingFactory.h"
#include "sourceCode/IndustrialBuildingFactory.h"
#include "sourceCode/BuildingComposite.h"
#include "sourceCode/Transport.h"
#include "sourceCode/Utilities.h"
#include "sourceCode/Government.h"
#include "sourceCode/BuildingComponent.h"
#include "sourceCode/PowerPlantFactory.h"
#include "sourceCode/WaterSupplyFactory.h"
#include "sourceCode/SewageSystemFactory.h"
#include "sourceCode/WasteManagementFactory.h"
#include "sourceCode/PolicyCommand.h"
#include "sourceCode/Command.h"
#include "sourceCode/TaxationCommand.h"
#include "sourceCode/Visitor.h"
#include "sourceCode/TaxCollector.h"
#include "sourceCode/Estate.h"
#include "sourceCode/House.h"
#include "sourceCode/Flat.h"
#include "sourceCode/mall.h"
#include "sourceCode/Office.h"
#include "sourceCode/Shop.h"
#include "sourceCode/School.h"
#include "sourceCode/University.h"
#include "sourceCode/Hospital.h"
#include "sourceCode/plant.h"
#include "sourceCode/SteelFactory.h"
#include "sourceCode/ConcreteFactory.h"
#include "sourceCode/WoodFactory.h"
#include "sourceCode/SavePointManager.h"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

class GameEngine {
private:
    std::shared_ptr<CityContext> cityContext;
    std::shared_ptr<BuildingFactory> buildingFactory;
    std::shared_ptr<ResidentialBuildingFactory> residentialFactory;
    std::shared_ptr<CommercialBuildingFactory> commercialFactory;
    std::shared_ptr<ServiceBuildingFactory> serviceFactory;
    std::shared_ptr<IndustrialBuildingFactory> indistrialFactory;
    std::shared_ptr<WaterSupplyFactory> waterSupply;
    std::shared_ptr<WasteManagementFactory> wasteManagement;
    std::shared_ptr<SewageSystemFactory> sewageSystem;
    std::shared_ptr<PowerPlantFactory> powerPlant;
    std::shared_ptr<Transport> transportSystem;
    std::shared_ptr<Government> government;
    std::vector<std::shared_ptr<AbstractCitizen>> citizens;
    SavePointManager savePointManager;

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
    void viewGameIndex();
    void upgradeBuilding(); 
    void addResources();
    void saveCheckpoint();
    void returnToLastCheckpoint();
};

#endif // GAMEENGINE_H
