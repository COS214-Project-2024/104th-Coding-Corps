//THIS IS JUST AN EXAMPLE OF HOW WE COULD START USING THIS THING

#include "GameEngine.h"
#include <iostream>
#include <string>

int main() {
    GameEngine game;
    game.displayIntro();
    std::cin.get(); // Pause for intro
    std::string buildingType;
    std::string district;
    std::string utilityType;
    std::string transportType;

    int choice;
    while (true) {
        game.displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter building type (Flat, House, etc.): ";
                
                std::cin >> buildingType;
                game.createBuilding(buildingType);
                break;

            case 2:
                std::cout << "Enter utility type (Power Plant, Water Supply, etc.): ";
                
                std::cin >> utilityType;
                game.createUtility(utilityType);
                break;

            case 3:
                game.upgradeBuilding();
                break;

            case 4:
                game.changeTaxPolicy();
                break;

            case 5:
                game.viewGameIndex();
                break;

            case 6:
                game.startSimulation();
                break;

            case 7:
                game.displayCitySummary();
                break;

            case 8:
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
