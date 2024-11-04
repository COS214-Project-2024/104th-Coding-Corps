#ifndef HOUSE_H
#define HOUSE_H

#include <memory>
#include "ResidentialBuildings.h"
#include "Government.h"

class House : public ResidentialBuildings {
private:
    int garageSize;
    bool pool;
    int residents;

public:
    House(int x, int y, const std::string& district, int quality, int garageSize, bool hasPool, int residents, int floors, bool hasGarden);

        // Copy constructor
    House(const House& other)
        : ResidentialBuildings(other), // Call the base class copy constructor
          garageSize(other.garageSize),
          pool(other.pool),
          residents(other.residents) {}

    // Clone function
    std::shared_ptr<BuildingComponent> clone() const override {
        return std::make_shared<House>(*this);
    }

    int getGarageSize() const;
    bool hasSwimmingPool() const;
    std::string getBuildingType() override;
    double getCost() override;
    double getMaintenanceCost() override;
    double getEnergyConsumption() override;
    double getWaterConsumption() override;
	int getNumResidents();
    void demolish() override;
    double getArea() override;
    int getOccupancy() override;
    std::string getType() const override {
        return "House"; // Return the specific type
    }
    void upgrade(std::shared_ptr<BuildingComponent> building) override;
};

#endif // HOUSE_H
