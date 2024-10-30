#include "School.h"
#include <iostream>

School::School(int quality, int numWorkers, int highestQualification)
    : ServiceBuildings(quality, numWorkers), highestQualification(highestQualification) {}

std::string School::getBuildingType() {
    return "School";
}

int School::getOccupancy() {
    return 1500;
}

double School::getCost() {
    return 3000000.0; // Example cost in ZAR
}

double School::getMaintenanceCost() {
    return 0.03 * getCost(); // 3% of cost as maintenance
}

double School::getEnergyConsumption() {
    return numWorkers * 200.0; // 200 kWh per worker per month
}

double School::getWaterConsumption() {
    return numWorkers * 80.0; // 80 liters per worker per month
}

void School::demolish() {
    std::cout << "Demolishing the school building." << std::endl;
    highestQualification = 0;
    quality = 0;
    numWorkers = 0;
}

void School::upgrade(BuildingComponent* building) {
    //figure out
}

double School::getArea() {
    return getX() * getY();
}

int School::getHighestQualification() {
    return highestQualification;
}
