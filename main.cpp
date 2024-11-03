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
        while (true) {
        std::cout << "Enter your choice (integer only): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter an integer.\n";
        } else {
            break; 
        }
    }

        switch (choice) {
            case 1:
                std::cout << "Enter building type (Flat, House, Estate, Factory, Plant, Warehouse, Office, Mall, Shop, School, University, Hospital): ";
                
                std::cin >> buildingType;
                game.createBuilding(buildingType);
                break;

            case 2:
                std::cout << "Enter utility type (Power Plant, Water Supply, Sewage Management, Waste Management): ";
                
                std::cin >> utilityType;
                game.createUtility(utilityType);
                break;

            case 3:
                game.upgradeBuilding(); //DOESNT WORK DOESNT WORK
                break;

            case 4:
                game.addResources();
                break;

            case 5:
                game.changeTaxPolicy();
                break;

            case 6:
                game.viewGameIndex();
                break;

            case 7:
                game.saveCheckpoint();
                break;

            case 8:
                game.returnToLastCheckpoint();
                break;
            
            case 9:
                game.startSimulation();
                break;

            case 10:
                game.displayCitySummary();
                break;

            case 11:
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}