#include "GameEngine.h"
#include <iostream>
#include <iomanip>

GameEngine::GameEngine() 
    : budget(1000000) {
    // Initialize CityContext and other subsystem components
    cityContext = CityContext::getInstance();
    buildingFactory = std::make_unique<BuildingFactory>();
    transportSystem = std::make_shared<Transport>();
    government = std::make_shared<Government>();
}

void GameEngine::displayIntro() {
    std::cout << "==============================================================\n";
    std::cout << "             WELCOME TO CITY BUILDER SIMULATION\n";
    std::cout << "==============================================================\n";
    std::cout << "Your goal is to build a prosperous city by managing resources, "
              << "building infrastructure, and ensuring citizens' well-being.\n\n";
    std::cout << "Starting Budget: $" << budget << "\n";
    std::cout << "Press [Enter] to continue...\n";
}

void GameEngine::displayMenu() {
    std::cout << "==============================================================\n";
    std::cout << "                  CITY MANAGEMENT MENU\n";
    std::cout << "==============================================================\n";
    std::cout << "Budget: $" << budget << "\n";
    std::cout << "1. Create Buildings\n";
    std::cout << "2. Create Utility Buildings\n";
    std::cout << "3. Change Tax Policy\n";
    std::cout << "4. Introduce New Transport\n";
    std::cout << "5. Start the Game Simulation\n";
    std::cout << "6. View City Summary\n";
    std::cout << "7. Exit Game\n";
    std::cout << "Select an option (1-7): ";
}

void GameEngine::createBuilding(const std::string& type) {
    double cost = 0;

    // Example of creating buildings based on type
    if (type == "Flat") {
        cost = 50000;
        if (budget >= cost) {
            auto flat = buildingFactory->createFlat(4, 4, 2, true);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(flat));
            budget -= cost;
            std::cout << "Flat created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget.\n";
        }
    }
    // Repeat for other building types
}

void GameEngine::createUtility(const std::string& type) {
    double cost = 0;

    // Example of creating utilities based on type
    if (type == "Power Plant") {
        cost = 500000;
        if (budget >= cost) {
            auto powerPlant = std::make_shared<PowerPlant>();
            cityContext->addUtility(powerPlant);
            budget -= cost;
            std::cout << "Power Plant created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget.\n";
        }
    }
    // Repeat for other utility types
}

void GameEngine::changeTaxPolicy(double newRate) {
    government->setTaxRate(newRate);
    std::cout << "Tax rate updated to " << newRate * 100 << "%.\n";
}

void GameEngine::addTransport(const std::string& type) {
    // Example of adding transport infrastructure
    if (type == "Bus") {
        double cost = 100000;
        if (budget >= cost) {
            transportSystem->addTransport(type);
            budget -= cost;
            std::cout << "Bus transport added. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget.\n";
        }
    }
}

void GameEngine::startSimulation() {
    // Example of simulation logic where citizens interact with city context
    cityContext->notify(); // Notify citizens of any updates
    std::cout << "Simulation running...\n";

    // Placeholder logic to perform actions in simulation
    for (auto& citizen : cityContext->getCitizens()) {
        citizen->goToWork();
        citizen->goToShops();
        citizen->getEducated();
    }

    std::cout << "Simulation complete.\n";
    displayCitySummary();
}

void GameEngine::displayCitySummary() {
    cityContext->getCitySummary();
    std::cout << "Current Budget: $" << budget << "\n";
}
