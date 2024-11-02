#include "GameEngine.h"


GameEngine::GameEngine() 
    : budget(10000000) {
    // Initialize CityContext and other subsystem components
    cityContext = CityContext::getInstance();
    buildingFactory = std::make_shared<BuildingFactory>();
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
    std::cout << "4. View Game Index\n";
    std::cout << "5. Start the Game Simulation\n";
    std::cout << "6. View City Summary\n";
    std::cout << "7. Exit Game\n";
    std::cout << "Select an option (1-7): ";
}

void GameEngine::createBuilding(const std::string& type, std::string district) {
    double cost = 0;

    if (type == "Flat") {
        cost = 1595000.00;
        if (budget >= cost) {
            auto flat = buildingFactory->createFlat(20, 50, 4, true, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(flat)));
            budget -= cost;
            std::cout << "Flat created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Flat.\n";
        }
    } else if (type == "House") {
        cost = 7000000;
        if (budget >= cost) {
            auto house = buildingFactory->createHouse(2, true, 4, 2, true, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(house)));
            budget -= cost;
            std::cout << "House created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for House.\n";
        }
    } else if (type == "Estate") {
        cost = 3000000;
        if (budget >= cost) {
            auto estate = buildingFactory->createEstate(2, true, 4, 2, true, 10, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(estate)));
            budget -= cost;
            std::cout << "Estate created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Estate.\n";
        }
    } else if (type == "Factory") {
        cost = 150000000;
        if (budget >= cost) {
            auto factory = buildingFactory->createFactory(0, 0, district, 50, 50, "factory", 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(factory)));
            budget -= cost;
            std::cout << "Factory created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Factory.\n";
        }
    } else if (type == "Plant") {
        cost = 220000000;
        if (budget >= cost) {
            auto plant = buildingFactory->createPlant(0, 0, district, 50, 200, 60);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(plant)));
            budget -= cost;
            std::cout << "Plant created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Plant.\n";
        }
    } else if (type == "Warehouse") {
        cost = 90000000;
        if (budget >= cost) {
            auto warehouse = buildingFactory->createWarehouse(0, 0, district, 50, 1000, 20);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(warehouse)));
            budget -= cost;
            std::cout << "Warehouse created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Warehouse.\n";
        }
    } else if (type == "Office") {
        cost = 3000000;
        if (budget >= cost) {
            auto office = buildingFactory->createOffice(100, "Tech", district, 50, 0, 0);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(office)));
            budget -= cost;
            std::cout << "Office created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Office.\n";
        }
    } else if (type == "Mall") {
        cost = 20 * 3000000;
        if (budget >= cost) {
            auto mall = buildingFactory->createMall(20, "Retail", 10, 0, 0, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(mall)));
            budget -= cost;
            std::cout << "Mall created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Mall.\n";
        }
    } else if (type == "Shop") {
        cost = 2000000;
        if (budget >= cost) {
            auto shop = buildingFactory->createShop(20, "Grocery", 0, 0, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(shop)));
            budget -= cost;
            std::cout << "Shop created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Shop.\n";
        }
    } else if (type == "School") {
        cost = 3000000;
        if (budget >= cost) {
            auto school = buildingFactory->createSchool(0, 0, district, 3, 50, 30);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(school)));
            budget -= cost;
            std::cout << "School created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for School.\n";
        }
    } else if (type == "University") {
        cost = 10000000;
        if (budget >= cost) {
            auto university = buildingFactory->createUniversity(0, 0, district, 5, 80, 100);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(university)));
            budget -= cost;
            std::cout << "University created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for University.\n";
        }
    } else if (type == "Hospital") {
        cost = 7000000;
        if (budget >= cost) {
            auto hospital = buildingFactory->createHospital(0, 0, district, 50, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(hospital)));
            budget -= cost;
            std::cout << "Hospital created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Hospital.\n";
        }
    } else {
        std::cout << "Invalid building type: " << type << "\n";
    }
}

void GameEngine::createUtility(const std::string& type) {
    double cost = 0;

    std::shared_ptr<Utilities> utility;

    // Use factory pattern to create utility
    if (type == "Power Plant") {
        cost = 200000;
        if (budget >= cost) {
            PowerPlantFactory powerPlantFactory;
            utility = powerPlantFactory.createUtilityService();
        }
    } else if (type == "Water Supply") {
        cost = 50000;
        if (budget >= cost) {
            WaterSupplyFactory waterSupplyFactory;
            utility = waterSupplyFactory.createUtilityService();
        }
    } else if (type == "Sewage Management") {
        cost = 120000;
        if (budget >= cost) {
            SewageSystemFactory sewageSystemFactory;
            utility = sewageSystemFactory.createUtilityService();
        }
    } else if (type == "Waste Management") {
        cost = 100000;
        if (budget >= cost) {
            WasteManagementFactory wasteManagementFactory;
            utility = wasteManagementFactory.createUtilityService();
        }
    }

    if (utility) {
        cityContext->addUtility(utility);
        budget -= cost;
        std::cout << type << " created. New Budget: $" << budget << "\n";
    } else if (cost > budget) {
        std::cout << "Insufficient budget.\n";
    } else {
        std::cout << "Unknown utility type.\n";
    }
}

void GameEngine::changeTaxPolicy() {
    std::string newRate;
    int option;

    // Display options for the user
    std::cout << "Select the new tax rate:\n";
    std::cout << "1. Low\n";
    std::cout << "2. Standard\n";
    std::cout << "3. High\n";
    std::cout << "Enter the number corresponding to your choice: ";
    std::cin >> option;

    // Determine the newRate based on the user's input
    switch (option) {
        case 1:
            newRate = "low";
            break;
        case 2:
            newRate = "standard";
            break;
        case 3:
            newRate = "high";
            break;
        default:
            std::cout << "Invalid selection. Please enter 1, 2, or 3.\n";
            return;  // Exit the function if an invalid option was chosen
    }

    // Create and execute the PolicyCommand with the selected tax rate
    PolicyCommand taxPolicyCommand(cityContext, government, "tax rate", newRate);
    taxPolicyCommand.execute();

    // Confirm the change to the user
    std::cout << "Tax rate policy updated to '" << newRate << "'.\n";
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
