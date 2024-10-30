//THIS IS JUST AN EXAMPLE OF HOW WE COULD START USING THIS THING

#include "GameEngine.h"
#include <iostream>

int main() {
    GameEngine game;
    game.displayIntro();
    std::cin.get(); // Pause for intro

    int choice;
    while (true) {
        game.displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter building type (Flat, House, etc.): ";
                std::string buildingType;
                std::cin >> buildingType;
                game.createBuilding(buildingType);
                break;

            case 2:
                std::cout << "Enter utility type (Power Plant, Water Supply, etc.): ";
                std::string utilityType;
                std::cin >> utilityType;
                game.createUtility(utilityType);
                break;

            case 3:
                std::cout << "Enter new tax rate (e.g., 0.1 for 10%): ";
                double taxRate;
                std::cin >> taxRate;
                game.changeTaxPolicy(taxRate);
                break;

            case 4:
                std::cout << "Enter transport type (Bus, Train, etc.): ";
                std::string transportType;
                std::cin >> transportType;
                game.addTransport(transportType);
                break;

            case 5:
                game.startSimulation();
                break;

            case 6:
                game.displayCitySummary();
                break;

            case 7:
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
