#include "Hospital.h"
#include <iostream>

Hospital::Hospital(int quality, int numWorkers)
    : ServiceBuildings(quality, numWorkers){}

std::string Hospital::getBuildingType() {
    return "Hospital";
}

int Hospital::getOccupancy() {
    return 5000;
}

double Hospital::getCost() {
    return 7000000.0; 
}

double Hospital::getMaintenanceCost() {
    return 0.05 * getCost(); 
}

double Hospital::getEnergyConsumption() {
    return numWorkers * 400.0; 
}

double Hospital::getWaterConsumption() {
    return numWorkers * 150.0; 
}

void Hospital::demolish() {
    std::cout << "Demolishing the hospital building." << std::endl;
    qualityOfCare = 0;
    quality = 0;
    numWorkers = 0;
}

void Hospital::upgrade(BuildingComponent* building) {
    // Implement upgrade logic
}

double Hospital::getArea() {
    return getX() * getY();
}

int Hospital::getQualityOfCare() {
    return qualityOfCare;
}
