#include "ResidentialBuildings.h"

#include "ResidentialBuildings.h"

ResidentialBuildings::ResidentialBuildings(int x, int y, const std::string& district, int quality, int residents, int floors, bool hasGarden)
    : BuildingComponent(x, y, district, quality), numResidents(residents), numFloors(floors), garden(hasGarden) {
    // Constructor implementation can remain empty if initialization is done in the initializer list
}

int ResidentialBuildings::getNumResidents() const {
    return this->numResidents;
}

int ResidentialBuildings::getNumFloors() const {
    return this->numFloors;
}

bool ResidentialBuildings::hasGarden() const {
    return garden;
}