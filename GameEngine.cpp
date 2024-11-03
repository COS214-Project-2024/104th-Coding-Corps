#include "GameEngine.h"
#include <algorithm>

/**
 * @brief Constructs the GameEngine, initializing core components and setting the starting budget.
 */
GameEngine::GameEngine() 
    : currentComposite(nullptr) {
    // Initialize CityContext and other subsystem components
    //making factories
    buildingFactory = std::make_shared<BuildingFactory>();
    residentialFactory = std::make_shared<ResidentialBuildingFactory>();
    commercialFactory = std::make_shared<CommercialBuildingFactory>();
    serviceFactory = std::make_shared<ServiceBuildingFactory>();
    industrialFactory = std::make_shared<IndustrialBuildingFactory>();
    waterSupply = std::make_shared<WaterSupplyFactory>();
    wasteManagement = std::make_shared<WasteManagementFactory>();
    sewageSystem = std::make_shared<SewageSystemFactory>();
    powerPlant = std::make_shared<PowerPlantFactory>();

    //setting up background city stuff
    transportSystem = std::make_shared<Transport>();
    government = Government::getInstance();
    cityContext = CityContext::getInstance(government);
    government->increaseBudget(40000000);

    //making districts
    for (char c = 'A'; c <= 'Z'; ++c) {
        districts.push_back(std::string(1, c));
    }

    //creating buildings for bro so his citizens arent totally miffed out
    auto utility = powerPlant->createUtilityService();
    cityContext->addUtility(utility);
    auto flat = residentialFactory->createFlat(20, 50, 4, true, "A", 50);
    cityContext->addBuilding(std::shared_ptr<BuildingComponent>(std::move(flat)));
    if (!currentComposite) {
        currentComposite = std::make_shared<BuildingComposite>(0,0,"A",50);
    }
    currentComposite->addBuilding(std::shared_ptr<BuildingComponent>(std::move(flat)));

    createCitizens(500);
}

/**
 * @brief Displays the introduction message and starting budget to the player.
 */
void GameEngine::displayIntro() {
    std::cout << "==============================================================\n";
    std::cout << "             WELCOME TO CITY BUILDER SIMULATION\n";
    std::cout << "==============================================================\n";
    std::cout << "Your goal is to build a prosperous city by managing resources, "
              << "building infrastructure, and ensuring citizens' well-being.\n"
              << "Start by adding some buildings for your citizens to live in!\n\n";
    std::cout << "Starting Budget: $" <<  std::fixed << std::setprecision(2) << government->getBalance() << "\n";
    std::cout << "Press [Enter] to continue...\n";
}

/**
 * @brief Displays the main menu for city management options.
 */
void GameEngine::displayMenu() {
    std::cout << "==============================================================\n";
    std::cout << "                  CITY MANAGEMENT MENU\n";
    std::cout << "==============================================================\n";
    std::cout << "Budget: $" << std::fixed << std::setprecision(2) << government->getBalance() << "\n"; 
    std::cout << "1. Create Buildings\n";
    std::cout << "2. Create Utility Buildings\n";
    std::cout << "3. Upgrade Building\n";
    std::cout << "4. Get More Resources\n";
    std::cout << "5. Change Tax Policy\n";
    std::cout << "6. Change Policy\n";
    std::cout << "7. View Game Index\n";
    std::cout << "8. Save Current City\n";
    std::cout << "9. Return to last city save\n";
    std::cout << "10. Start the Game Simulation\n";
    std::cout << "11. View City Summary\n";
    std::cout << "12. Exit Game\n";
    std::cout << "Select an option (1-12):" << std::endl;
}

/**
 * @brief Creates a building of the specified type in the current district if budget allows.
 * @param typeCode An integer representing the building type.
 */
void GameEngine::createBuilding(int typeCode) {
    double funBudget = government->getBalance();
    double cost = 0;
    std::string district = districts[currentDistrictIndex];

    // Ensure the current composite exists
    if (!currentComposite) {
        currentComposite = std::make_shared<BuildingComposite>(0, 0, district, 50);
    }

    switch (typeCode) {
        case 1: { // Flat
            cost = 1595000.00;
            if (funBudget >= cost) {
                auto flat = residentialFactory->createFlat(20, 50, 4, true, district, 50);
                auto flatPtr = std::shared_ptr<BuildingComponent>(std::move(flat)); // Convert unique_ptr to shared_ptr
                cityContext->addBuilding(flatPtr);
                currentComposite->addBuilding(flatPtr);
                government->decreaseBudget(cost);
                std::cout << "Flat created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Flat.\n";
            }
            break;
        }
        case 2: { // House
            cost = 5000000.00;
            if (funBudget >= cost) {
                auto house = residentialFactory->createHouse(2, true, 4, 2, true, district, 50);
                auto housePtr = std::shared_ptr<BuildingComponent>(std::move(house));
                cityContext->addBuilding(housePtr);
                currentComposite->addBuilding(housePtr);
                government->decreaseBudget(cost);
                std::cout << "House created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for House.\n";
            }
            break;
        }
        case 3: { // Estate
            cost = 20000000.00;
            if (funBudget >= cost) {
                auto estate = residentialFactory->createEstate(2, true, 4, 2, true, 10, district, 50);
                auto estatePtr = std::shared_ptr<BuildingComponent>(std::move(estate));
                cityContext->addBuilding(estatePtr);
                currentComposite->addBuilding(estatePtr);
                government->decreaseBudget(cost);
                std::cout << "Estate created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Estate.\n";
            }
            break;
        }
        case 4: { // Factory
            cost = 18000000.00;
            if (funBudget >= cost) {
                auto factory = industrialFactory->createFactory(0, 0, district, 50, 50, "factory", 50);
                auto factoryPtr = std::shared_ptr<BuildingComponent>(std::move(factory));
                cityContext->addBuilding(factoryPtr);
                currentComposite->addBuilding(factoryPtr);
                government->decreaseBudget(cost);
                std::cout << "Factory created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Factory.\n";
            }
            break;
        }
        case 5: { // Plant
            cost = 7000000.00;
            if (funBudget >= cost) {
                auto plant = industrialFactory->createPlant(0, 0, district, 50, 200, 60);
                auto plantPtr = std::shared_ptr<BuildingComponent>(std::move(plant));
                cityContext->addBuilding(plantPtr);
                currentComposite->addBuilding(plantPtr);
                government->decreaseBudget(cost);
                std::cout << "Plant created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Plant.\n";
            }
            break;
        }
        case 6: { // Warehouse
            cost = 8000000.00;
            if (funBudget >= cost) {
                auto warehouse = industrialFactory->createWarehouse(0, 0, district, 50, 1000, 20);
                auto warehousePtr = std::shared_ptr<BuildingComponent>(std::move(warehouse));
                cityContext->addBuilding(warehousePtr);
                currentComposite->addBuilding(warehousePtr);
                government->decreaseBudget(cost);
                std::cout << "Warehouse created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Warehouse.\n";
            }
            break;
        }
        case 7: { // Office
            cost = 3000000.00;
            if (funBudget >= cost) {
                auto office = commercialFactory->createOffice(100, "Tech", district, 50, 0, 0);
                auto officePtr = std::shared_ptr<BuildingComponent>(std::move(office));
                cityContext->addBuilding(officePtr);
                currentComposite->addBuilding(officePtr);
                government->decreaseBudget(cost);
                std::cout << "Office created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Office.\n";
            }
            break;
        }
        case 8: { // Mall
            cost = 40000000.00;
            if (funBudget >= cost) {
                auto mall = commercialFactory->createMall(20, "Retail", 10, 0, 0, district, 50);
                auto mallPtr = std::shared_ptr<BuildingComponent>(std::move(mall));
                cityContext->addBuilding(mallPtr);
                currentComposite->addBuilding(mallPtr);
                government->decreaseBudget(cost);
                std::cout << "Mall created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Mall.\n";
            }
            break;
        }
        case 9: { // Shop
            cost = 2000000.00;
            if (funBudget >= cost) {
                auto shop = commercialFactory->createShop(20, "Grocery", 0, 0, district, 50);
                auto shopPtr = std::shared_ptr<BuildingComponent>(std::move(shop));
                cityContext->addBuilding(shopPtr);
                currentComposite->addBuilding(shopPtr);
                government->decreaseBudget(cost);
                std::cout << "Shop created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Shop.\n";
            }
            break;
        }
        case 10: { // School
            cost = 10000000.00;
            if (funBudget >= cost) {
                auto school = serviceFactory->createSchool(0, 0, district, 3, 50, 30);
                auto schoolPtr = std::shared_ptr<BuildingComponent>(std::move(school));
                cityContext->addBuilding(schoolPtr);
                currentComposite->addBuilding(schoolPtr);
                government->decreaseBudget(cost);
                std::cout << "School created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for School.\n";
            }
            break;
        }
        case 11: { // University
            cost = 25000000.00;
            if (funBudget >= cost) {
                auto university = serviceFactory->createUniversity(0, 0, district, 5, 80, 100);
                auto universityPtr = std::shared_ptr<BuildingComponent>(std::move(university));
                cityContext->addBuilding(universityPtr);
                currentComposite->addBuilding(universityPtr);
                government->decreaseBudget(cost);
                std::cout << "University created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for University.\n";
            }
            break;
        }
        case 12: { // Hospital
            cost = 15000000.00;
            if (funBudget >= cost) {
                auto hospital = serviceFactory->createHospital(0, 0, district, 50, 50);
                auto hospitalPtr = std::shared_ptr<BuildingComponent>(std::move(hospital));
                cityContext->addBuilding(hospitalPtr);
                currentComposite->addBuilding(hospitalPtr);
                government->decreaseBudget(cost);
                std::cout << "Hospital created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for Hospital.\n";
            }
            break;
        }
        default:
            std::cout << "Invalid building type code: " << typeCode << "\n";
            break;
    }

    // Check if the composite has enough buildings and save it if so
    if (currentComposite->getBuildingCount() == 10) {
        buildingComposites.push_back(currentComposite); // Store the composite
        currentComposite.reset();                       // Reset composite for the next set of buildings

        // Move to the next district
        currentDistrictIndex = (currentDistrictIndex + 1) % districts.size();
    }

    // Notify the user if funds are depleted
    if (government->getBalance() == 0) {
        std::cout << "You're out of cash! Start the simulation to earn more!" << std::endl;
    }
}

/**
 * @brief Creates a utility building of the specified type if budget allows.
 * @param type The type of utility to create.
 */
void GameEngine::createUtility(int typeCode) {
    double cost = 0;
    std::shared_ptr<Utilities> utility;

    switch (typeCode) {
        case 1: // PowerPlant
            cost = 200000;
            if (government->getBalance() >= cost) {
                utility = powerPlant->createUtilityService();
                cityContext->addUtility(utility);
                government->decreaseBudget(cost);
                std::cout << "PowerPlant created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for PowerPlant.\n";
            }
            break;

        case 2: // WaterSupply
            cost = 50000;
            if (government->getBalance() >= cost) {
                utility = waterSupply->createUtilityService();
                cityContext->addUtility(utility);
                government->decreaseBudget(cost);
                std::cout << "WaterSupply created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for WaterSupply.\n";
            }
            break;

        case 3: // SewageManagement
            cost = 120000;
            if (government->getBalance() >= cost) {
                utility = sewageSystem->createUtilityService();
                cityContext->addUtility(utility);
                government->decreaseBudget(cost);
                std::cout << "SewageManagement created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for SewageManagement.\n";
            }
            break;

        case 4: // WasteManagement
            cost = 100000;
            if (government->getBalance() >= cost) {
                utility = wasteManagement->createUtilityService();
                cityContext->addUtility(utility);
                government->decreaseBudget(cost);
                std::cout << "WasteManagement created. New Budget: $" << government->getBalance() << "\n";
            } else {
                std::cout << "Insufficient budget for WasteManagement.\n";
            }
            break;

        default:
            std::cout << "Unknown utility type.\n";
            break;
    }

    if (government->getBalance() == 0) {
        std::cout << "You're out of cash! Start the simulation to earn more!" << std::endl;
    }
}

void GameEngine::addResources(){
        // Define resource factories and quantities
    SteelFactory steelFactory;
    ConcreteFactory concreteFactory;
    WoodFactory woodFactory;

    // Add resources to the city through the government
    government->addResourceToCity("Steel", 100000, 10.0, steelFactory);
    government->addResourceToCity("Concrete", 20000, 8.0, concreteFactory);
    government->addResourceToCity("Wood", 15000, 5.0, woodFactory);
}

void GameEngine::upgradeBuilding() {
    // Prompt the user to select a building type to upgrade
    std::string buildingType;
    std::cout << "Select a building to upgrade (Estate, House, Flat, etc.): ";
    std::cin >> buildingType;

    std::shared_ptr<BuildingComponent> building = nullptr;

    // Use findBuilding to locate the building
    if (!buildingComposites.empty()) {  // Corrected condition check
        for (const auto& composite : buildingComposites) {
            if (composite) {  // Ensure composite is not nullptr
                building = composite->findBuilding(buildingType);
                if (building != nullptr) {
                    break;
                }
            }
        }
    }

    if (!building && currentComposite) {  // Only access currentComposite if it's not nullptr
        building = currentComposite->findBuilding(buildingType);
    }

    // Check if the building was found and perform the upgrade
    if (building) {
        building->upgrade(nullptr); // Pass nullptr or any necessary parameters
        //std::cout << buildingType << " upgraded successfully!\n";
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

    while (true) {
        std::cout << "Select the new tax rate:\n";
        std::cout << "1. Low\n";
        std::cout << "2. Standard\n";
        std::cout << "3. High\n";
        std::cout << "Enter the number corresponding to your choice: ";
        cin >> option;

        if (std::cin.fail() || option > 3 || option <1) {
            std::cin.clear(); // Clear 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter an integer (1-3).\n";
        } else {
            break; 
        }
    }


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
            return;  // Exit the function if an invalid option was chosen
    }
    // Create and execute the PolicyCommand with the selected tax rate
    PolicyCommand taxPolicyCommand(cityContext, government, "tax rate", newRate);
    taxPolicyCommand.execute();

    // Confirm the change to the user
    //std::cout << "Tax rate policy updated to '" << newRate << "'.\n";
}

void GameEngine::changePolicy() {
    int policyOption, valueOption;
    std::string selectedPolicy, newValue;

    // Display the list of policies to the user
    std::cout << "Select the policy you want to change:\n";
    std::cout << "1. Maximum number of power plants\n";
    std::cout << "2. Waste removal frequency\n";
    std::cout << "3. Maximum number of buildings per district\n";
    std::cout << "4. Renewable energy target\n";
    std::cout << "5. Police patrol frequency\n";
    std::cout << "6. School capacity limit\n";
    std::cout << "7. Tax rate\n";
    std::cout << "Enter the number corresponding to your choice: ";

    // Validate policy selection
    while (true) {
        std::cin >> policyOption;
        if (std::cin.fail() || policyOption < 1 || policyOption > 7) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer (1-7).\n";
        } else {
            break;
        }
    }

    // Map the policy option to the corresponding policy key
    switch (policyOption) {
        case 1:
            selectedPolicy = "Maximum number of power plants";
            break;
        case 2:
            selectedPolicy = "Waste removal frequency";
            break;
        case 3:
            selectedPolicy = "Maximum number of buildings per district";
            break;
        case 4:
            selectedPolicy = "Renewable energy target";
            break;
        case 5:
            selectedPolicy = "Police patrol frequency";
            break;
        case 6:
            selectedPolicy = "School capacity limit";
            break;
        case 7:
            selectedPolicy = "tax rate";
            break;
    }

    const auto& allowedOptions = cityContext->getAllowedValues(selectedPolicy);

    if (allowedOptions.empty()) {
        std::cerr << "No allowed values defined for the selected policy.\n";
        return;
    }

    // Display allowed values for the selected policy
    std::cout << "Choose a new value for " << selectedPolicy << ":\n";
    for (size_t i = 0; i < allowedOptions.size(); ++i) {
        std::cout << (i + 1) << ". " << allowedOptions[i] << "\n";
    }

    // Validate value selection
    while (true) {
        std::cout << "Please enter a value for the policy you would like to change" << std::endl;
        std::cin >> valueOption;
        if (std::cin.fail() || valueOption < 1 || valueOption > static_cast<int>(allowedOptions.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please select a valid option.\n";
        } else {
            newValue = allowedOptions[valueOption - 1];
            break;
        }
    }

    // Create and execute the PolicyCommand to enforce the policy change
    auto policyCommand = std::make_shared<PolicyCommand>(cityContext, government, selectedPolicy, newValue);
    government->setCommand(policyCommand);
    government->issueCommand();

    // Confirm the change to the user
    //std::cout << "Policy '" << selectedPolicy << "' updated to '" << newValue << "'.\n";
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
           std::cout << "Citizen Management\n";
           std::cout << "Each citizen's satisfaction is influenced by your management of the game.\n";
           std::cout << "Unhappy citizens (with a satisfaction bellow 25) will go on strike and stop participating in your economy!\n";
           std::cout << "Here's some tips on keeping them happy and active in your society:\n"
                    << "- Educating citizens increases their happiness and pushes them into higher earning jobs,"
                    << "so make sure to have enough educational facilities\n"
                    << "- Citizens like high quality buildings. Increase the quality through upgrades.\n"
                    << "-Some policies make citizens happier than others, it's your job to figure out which one they are.\n"
                    << "-Balance taxes with citizen happiness. They don't like high tax rates, but you may need it to improve your city!";
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
    for(int i = 0; i < 12; i++) {
        if(i > 0 && government->getBalance() == 0){
            std::cout << "GAME OVER :(( no more monies \n";
        }
        std::cout << "Simulation running... Month: " << (i + 1) << "\n";

        cityContext->notify();

        // Retrieve current population and average citizen satisfaction
        int populationSize = cityContext->calculateTotalPop();
        int citizenSatisfaction = cityContext->calculateAverageSatisfaction();
        double satisfactionFactor = static_cast<double>(citizenSatisfaction) / 100.0;        
        int birthCount = static_cast<int>(populationSize * 0.09 * satisfactionFactor);
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
        if(i == 11) {
            // Tax logic - Issue taxation command
            double taxRate = 0.1; 
            auto taxationCommand = std::make_shared<TaxationCommand>(citizens, taxRate);
            government->setCommand(taxationCommand);
            government->issueCommand(); // Apply taxes to citizens
        }

        std::cout << "End of month " << (i + 1) << " simulation.\n";
    }

    std::cout << "Simulation complete.\n";
    cityContext->prepareCitySummary();
    displayCitySummary();
}

/**
 * @brief Displays a summary of the city, including population and financial status.
 */
void GameEngine::displayCitySummary() {
    cityContext->getCitySummary();
    std::cout << "Current Budget: $" << government->getBalance() << "\n";
}

void GameEngine::saveCheckpoint() {
    // Create a new save point from the current CityContext state
    auto savePoint = cityContext->saveGame();

    savePointManager.saveState(savePoint);

    std::cout << "Checkpoint saved.\n";
}

void GameEngine::returnToLastCheckpoint() {
    // Use SavePointManager to retrieve the previous save point
    auto lastCheckpoint = savePointManager.undo();

    if (lastCheckpoint != nullptr) {
        // Restore the CityContext state from the retrieved save point
        cityContext->setSavePoint(lastCheckpoint);
        std::cout << "Returned to last checkpoint.\n";
    } else {
        std::cout << "No checkpoint to return to.\n";
    }
}
