#include "GameEngine.h"
#include <iostream>
#include <string>
#include <limits>

int main() {
    GameEngine game;
    game.displayIntro();

    // Ensure only Enter is pressed
    std::string input;
    while (true) {
        std::getline(std::cin, input);

        if (input.empty()) {
            break; // Proceed if only Enter was pressed
        } else {
            std::cout << "Please press only [Enter] to continue...\n";
        }
    }

    int buildingType;
    std::string district;
    int utilityType;
    std::string transportType;

    int choice;
    while (true) {
        game.displayMenu();

        while (true) {
            std::cout << "Enter your choice (integer only): ";
            std::cin >> choice;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
                std::cout << "Invalid input. Please enter an integer.\n";
            } else {
                break; 
            }
        }

        switch (choice) {
            case 1:
                system("clear");
                std::cout << "Choose a building type:\n";
                std::cout << "1. Flat ($1,595,000)\n";
                std::cout << "2. House ($5,000,000)\n";
                std::cout << "3. Estate ($20,000,000)\n";
                std::cout << "4. Factory ($18,000,000)\n";
                std::cout << "5. Plant ($7,000,000)\n";
                std::cout << "6. Warehouse ($8,000,000)\n";
                std::cout << "7. Office ($3,000,000)\n";
                std::cout << "8. Mall ($40,000,000)\n";
                std::cout << "9. Shop ($2,000,000)\n";
                std::cout << "10. School ($10,000,000)\n";
                std::cout << "11. University ($25,000,000)\n";
                std::cout << "12. Hospital ($15,000,000)\n";

                std::cout << "Enter the number of the building you wish to create: ";
                std::cin >> buildingType;

                game.createBuilding(buildingType);
                break;

            case 2:
                system("clear");
                std::cout << "Enter utility type:\n";
                std::cout << "1. PowerPlant ($200,000)\n";
                std::cout << "2. WaterSupply ($50,000)\n";
                std::cout << "3. SewageManagement ($120,000)\n";
                std::cout << "4. WasteManagement ($100,000)\n";
                std::cout << "Choose utility type by number: ";
                
                std::cin >> utilityType;

                game.createUtility(utilityType);
                break;

            case 3:
                system("clear");
                game.upgradeBuilding();
                break;

            case 4:
                system("clear");
                game.addResources();
                break;

            case 5:
                system("clear");
                game.changeTaxPolicy();
                break;

            case 6:
                system("clear");
                game.changePolicy();
                break;

            case 7:
                system("clear");
                game.viewGameIndex();
                break;

            case 8:
                system("clear");
                game.saveCheckpoint();
                break;

            case 9:
                system("clear");
                game.returnToLastCheckpoint();
                break;
            
            case 10:
                system("clear");
                game.startSimulation();
                if(game.getGameOver() == true) {
                    return 0;
                }
                break;

            case 11:
                system("clear");
                game.displayCitySummary();
                break;

            case 12:
                system("clear");
                std::cout << "Exiting game.\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
