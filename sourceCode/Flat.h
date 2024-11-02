#ifndef FLAT_H
#define FLAT_H

#include <memory>
#include "ResidentialBuildings.h"
#include "Government.h"

class Flat : public ResidentialBuildings {
private:
    int numUnits;

public:
    Flat(int x, int y, const std::string& district, int quality, int units, int residents, int floors, bool hasGarden);

    int getNumUnits() const;
    std::string getBuildingType() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
    void demolish() override;
    double getArea() override;
    int getOccupancy() override;
	int getNumResidents();
    std::string getType() const override {
        return "Flat"; // Return the specific type
    }
    void upgrade(std::shared_ptr<BuildingComponent> building) override;
};

#endif // FLAT_H
