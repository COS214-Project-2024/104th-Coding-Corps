#include "GameEngine.h"
#include <algorithm>

/**
 * @brief Constructs the GameEngine, initializing core components and setting the starting budget.
 */
GameEngine::GameEngine() 
    : budget(100000000), currentComposite(nullptr) {
    // Initialize CityContext and other subsystem components
    cityContext = CityContext::getInstance();
    buildingFactory = std::make_shared<BuildingFactory>();
    transportSystem = std::make_shared<Transport>();
    government = Government::getInstance();

    for (char c = 'A'; c <= 'Z'; ++c) {
        districts.push_back(std::string(1, c));
    }

    createCitizens(100);
}

/**
 * @brief Displays the introduction message and starting budget to the player.
 */
void GameEngine::displayIntro() {
    std::cout << "==============================================================\n";
    std::cout << "             WELCOME TO CITY BUILDER SIMULATION\n";
    std::cout << "==============================================================\n";
    std::cout << "Your goal is to build a prosperous city by managing resources, "
              << "building infrastructure, and ensuring citizens' well-being.\n\n";
    std::cout << "Starting Budget: $" <<  std::fixed << std::setprecision(2) << budget << "\n";
    std::cout << "Press [Enter] to continue...\n";
}

/**
 * @brief Displays the main menu for city management options.
 */
void GameEngine::displayMenu() {
    std::cout << "==============================================================\n";
    std::cout << "                  CITY MANAGEMENT MENU\n";
    std::cout << "==============================================================\n";
    std::cout << "Budget: $" << std::fixed << std::setprecision(2) << budget << "\n"; 
    std::cout << "1. Create Buildings\n";
    std::cout << "2. Create Utility Buildings\n";
    std::cout << "3. Upgrade Building\n";
    std::cout << "4. Change Tax Policy\n";
    std::cout << "5. View Game Index\n";
    std::cout << "6. Start the Game Simulation\n";
    std::cout << "7. View City Summary\n";
    std::cout << "8. Exit Game\n";
    std::cout << "Select an option (1-7): ";

}

/**
 * @brief Creates a building of the specified type in the current district if budget allows.
 * @param type The type of building to create.
 */
void GameEngine::createBuilding(const std::string& type) {
    double cost = 0;
    std::string district = districts[currentDistrictIndex];

    if (!currentComposite) {
        currentComposite = std::make_shared<BuildingComposite>(0,0,district,50);
    }

    if (type == "Flat") {
        cost = 1595000.00;
        if (budget >= cost) {
            auto flat = buildingFactory->createFlat(20, 50, 4, true, district, 50);
            cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(flat)));
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(flat)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(house)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(estate)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(factory)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(plant)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(warehouse)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(office)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(mall)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(shop)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(university)));
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
            currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(hospital)));
            budget -= cost;
            std::cout << "Hospital created. New Budget: $" << budget << "\n";
        } else {
            std::cout << "Insufficient budget for Hospital.\n";
        }
    } else {
        std::cout << "Invalid building type: " << type << "\n";
    }

    if (currentComposite->getBuildingCount() == 10) {  // Assuming getBuildingCount() returns the number of buildings
        cityContext->addBuilding(currentComposite);    // Add the complete composite to city context
        buildingComposites.push_back(currentComposite); // Store the composite
        currentComposite.reset();                       // Reset composite for the next set of buildings

        // Move to the next district
        currentDistrictIndex = (currentDistrictIndex + 1) % districts.size();
    }

    if(budget == 0){
        std::cout << "You're out of cash! Start the simulation to earn more!" << std:: endl;
    }
}
/**
 * @brief Creates a utility building of the specified type if budget allows.
 * @param type The type of utility to create.
 */
void GameEngine::createUtility(const std::string& type) {
    double cost = 0;

    std::shared_ptr<Utilities> utility;

    // Use factory pattern to create utility
    if (type == "Power Plant") {
        cost = 200000;
        if (budget >= cost) {
            PowerPlantFactory powerPlantFactory;
            utility = powerPlantFactory.createUtilityService();
            cityContext->addUtility(utility);
            budget -= cost;
            std::cout << type << " created. New Budget: $" << budget << "\n";
        }
    } else if (type == "Water Supply") {
        cost = 50000;
        if (budget >= cost) {
            WaterSupplyFactory waterSupplyFactory;
            utility = waterSupplyFactory.createUtilityService();
            cityContext->addUtility(utility);
            budget -= cost;
            std::cout << type << " created. New Budget: $" << budget << "\n";
        }
    } else if (type == "Sewage Management") {
        cost = 120000;
        if (budget >= cost) {
            SewageSystemFactory sewageSystemFactory;
            utility = sewageSystemFactory.createUtilityService();
            cityContext->addUtility(utility);
            budget -= cost;
            std::cout << type << " created. New Budget: $" << budget << "\n";
        }
    } else if (type == "Waste Management") {
        cost = 100000;
        if (budget >= cost) {
            WasteManagementFactory wasteManagementFactory;
            utility = wasteManagementFactory.createUtilityService();
            cityContext->addUtility(utility);
            budget -= cost;
            std::cout << type << " created. New Budget: $" << budget << "\n";
        }
    }
    else{
        std::cout << "Unknown utility type.\n";
    }

    if (cost > budget) {
        std::cout << "Insufficient budget.\n";
    }

    if(budget == 0){
        std::cout << "You're out of cash! Start the simulation to earn more!" << std:: endl;
    }

}

void GameEngine::upgradeBuilding() {
    // Define resource factories and quantities
    SteelFactory steelFactory;
    ConcreteFactory concreteFactory;
    WoodFactory woodFactory;

    // Add resources to the city through the government
    government->addResourceToCity("Steel", 100000, 10.0, steelFactory);
    government->addResourceToCity("Concrete", 20000, 8.0, concreteFactory);
    government->addResourceToCity("Wood", 15000, 5.0, woodFactory);

    // Prompt the user to select a building type to upgrade
    std::string buildingType;
    std::cout << "Select a building to upgrade (Estate, House, Flat, etc.): ";
    std::cin >> buildingType;

    // Use findBuilding to locate the building
    std::shared_ptr<BuildingComponent> building = currentComposite->findBuilding(buildingType);
    
    // Check if the building was found and perform the upgrade
    if (building) {
        building->upgrade(nullptr); // Pass nullptr or any necessary parameters
        std::cout << buildingType << " upgraded successfully!\n";
    } else {
        std::cout << "No " << buildingType << " found to upgrade.\n";
    }
}



/**
 * @brief Allows the user to change the tax policy through a menu.
 */
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

/**
 * @brief Creates a specified number of citizens and adds them to the CityContext.
 * @param n The number of citizens to create.
 */
void GameEngine::createCitizens(int n){

    for (int i = 0; i < n; ++i){
        // Create a new Citizen with the required contexts
        auto newCitizen = std::make_shared<Citizen>(cityContext, transportSystem, government);
        cityContext->attach(newCitizen);
        newCitizen->initialize();
        citizens.push_back(newCitizen);
    }
}

void GameEngine::viewGameIndex(){
     int choice;
    
    std::cout << "\n======================== INFORMATION MENU ========================\n";
    std::cout << "| Here you can find additional information on the proper         |\n";
    std::cout << "| management of your city!                                       |\n";
    std::cout << "| Select a topic to learn more about:                            |\n";
    std::cout << "| 1. Citizen Management                                          |\n";
    std::cout << "| 2. Building and Utility Creation                               |\n";
    std::cout << "| 3. Government Taxation and Policies                            |\n";
    std::cout << "==================================================================\n";
    std::cout << "Enter the number of the topic you'd like to learn more about: ";
    std::cin >> choice;

    std::cout << "\n======================== INFORMATION DETAILS =====================\n";

    switch (choice) {
        case 1:
           //displayCitizenInfoMenu();
            break;
            
        case 2:
            std::cout << "Building and Utility Creation:\n";
            std::cout << "  -  You can build a wide variety of BUILDINGS for Residential, Commercial, Industrial and Service sectors.\n";
            std::cout << "  - Residential: Flat , House , Estate.\n";
            std::cout << "  - Commercial: Shop , Mall , Office.\n";
            std::cout << "  - Industrial: Factory , Plant , WareHouse.\n";
            std::cout << "  - Service: School , University , Hospital.\n";
            std::cout << "  - Ensure you have enough residential, service and commercial buildings to service and supply your population!.\n";
            std::cout << "  - Create UTILITIES like a Power Plant , Water Supply, Sewage Management and Waste Management facilities \n"
                         "to meet the needs of a growing population.\n";
            std::cout << "  - Hint! Buildings increase a city's energy and water needs.\n";
            std::cout << "  - Each building and utility impacts citizen satisfaction and the city's economy.\n";
            std::cout << "  - The quality of the building matters! Upgrade buildings to keep citizens happy.\n";
            std::cout << "  - Upgrades will use city resources.\n";
            std::cout << "  - Utilities cannot be upgraded.\n";
            break;

        case 3:
            std::cout << "Government Taxation and Policies:\n";
            std::cout << "  - Set tax policies to balance citizen satisfaction with city revenue.\n";
            std::cout << "  - Policy options include adjusting tax rates, regulating construction, and setting "
                         "citywide rules on resource usage.\n";
            std::cout << "  - Policies can impact citizen happiness and the city's financial status.\n";
            break;

        default:
            std::cout << "Invalid selection. Please choose a valid topic number.\n";
            break;
    }

    std::cout << "==================================================================\n";
}


/**
 * @brief Starts the city simulation, updating citizens, applying tax, and displaying the summary.
 */
void GameEngine::startSimulation() {
    // Initialize random number generator
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); // Random seed

    // Simulation loop for each month (or cycle)
    for (int i = 0; i < 12; i++) {
        std::cout << "Simulation running... Month: " << (i + 1) << "\n";

        // Update citizens with the latest context
        cityContext->notify();

        // Retrieve current population and average citizen satisfaction
        int populationSize = cityContext->calculateTotalPop();
        int citizenSatisfaction = cityContext->calculateAverageSatisfaction();

        // Calculate birth rate using population size and satisfaction
        double baseBirthRate = 0.5; // Adjust as needed
        double satisfactionFactor = citizenSatisfaction / 100.0; // Scale satisfaction between 0 and 1
        int birthCount = static_cast<int>(populationSize * baseBirthRate * satisfactionFactor);

        // Add randomness to vary birth count by ±20%
        std::uniform_int_distribution<> variation(-birthCount * 0.2, birthCount * 0.2);
        birthCount += variation(gen);

        // Create new citizens based on the calculated birth count
        createCitizens(birthCount);

        // Update population size after births
        int totalPopulation = cityContext->calculateTotalPop();

        // Set up activity distribution among citizens
        std::uniform_int_distribution<> schoolRange(totalPopulation * 0.3, totalPopulation * 0.5);
        std::uniform_int_distribution<> uniRange(totalPopulation * 0.3, totalPopulation * 0.5);
        std::uniform_int_distribution<> workRange(totalPopulation * 0.4, totalPopulation * 0.6);
        std::uniform_int_distribution<> shopRange(totalPopulation * 0.3, totalPopulation * 0.5);
        std::uniform_int_distribution<> hospitalRange(totalPopulation * 0.05, totalPopulation * 0.1);

        // Decide the count for each activity based on ranges
        int schoolCount = schoolRange(gen);
        int uniCount = uniRange(gen);
        int workCount = workRange(gen);
        int shopCount = shopRange(gen);
        int hospitalCount = hospitalRange(gen);

        // Retrieve the list of citizens and shuffle for random activity assignment
        auto citizensMap = cityContext->getCitizens();
        std::vector<std::shared_ptr<AbstractCitizen>> citizens;
        for (const auto& [id, citizen] : citizensMap) {
            citizens.push_back(citizen);
        }
        std::shuffle(citizens.begin(), citizens.end(), gen);

        // Assign activities to citizens
        for (int i = 0; i < schoolCount && i < totalPopulation; ++i) {
            citizens[i]->getSchooled();
        }
        for (int i = 0; i < uniCount && i < totalPopulation; ++i) {
            citizens[i]->getEducated();
        }
        for (int i = 0; i < workCount && i < totalPopulation; ++i) {
            citizens[i]->goToWork();
        }
        for (int i = 0; i < shopCount && i < totalPopulation; ++i) {
            citizens[i]->goToShops();
        }
        for (int i = 0; i < hospitalCount && i < totalPopulation; ++i) {
            citizens[i]->getHealed();
        }

        // Tax logic - Issue taxation command
        double taxRate = 0.1; 
        auto taxationCommand = std::make_shared<TaxationCommand>(citizens, taxRate);
        government->setCommand(taxationCommand);
        government->issueCommand(); // Apply taxes to citizens

        std::cout << "End of month " << (i + 1) << " simulation.\n";
    }

    std::cout << "Simulation complete.\n";
    displayCitySummary();
}



/**
 * @brief Displays a summary of the city, including population and financial status.
 */
void GameEngine::displayCitySummary() {
    cityContext->getCitySummary();
    std::cout << "Current Budget: $" << budget << "\n";
}
