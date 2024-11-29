#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utilities.h"
#include "BuildingComponent.h"
#include <string>
#include <memory> // For std::shared_ptr

class WaterSupply : public Utilities {

public:
    // Typedef for easier use of shared_ptr<WaterSupply>
    using Ptr = std::shared_ptr<WaterSupply>;

    WaterSupply();

    double getConsumptionRate() override;

    double getCost() override;

    void activateUtility() override;

    void deactivateUtility() override;

    void distributeWater(std::shared_ptr<BuildingComponent> building); // Use shared_ptr here as well
};

#endif
