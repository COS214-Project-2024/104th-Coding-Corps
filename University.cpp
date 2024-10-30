#include "University.h"
#include <iostream>

University::University(int quality, int numWorkers, int highestQualification)
    : ServiceBuildings(quality, numWorkers), highestQualification(highestQualification) {}

std::string University::getBuildingType() {
    return "University";
}

int University::getOccupancy() {
    return 20000; 
}

double University::getCost() {
    return 10000000.0; 
}

double University::getMaintenanceCost() {
    return 0.04 * getCost();
}

double University::getEnergyConsumption() {
    return numWorkers * 300.0; 
}

double University::getWaterConsumption() {
    return numWorkers * 100.0; 
}

void University::demolish() {
    std::cout << "Demolishing the university building." << std::endl;
    highestQualification = 0;
    quality = 0;
    numWorkers = 0;
}

void University::upgrade(BuildingComponent* building) {
}

double University::getArea() {
    return getX() * getY();
}

int University::getHighestQualification() {
    return highestQualification;
}
