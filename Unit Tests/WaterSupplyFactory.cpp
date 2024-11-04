#include "WaterSupplyFactory.h"
#include "WaterSupply.h" // Assuming WaterSupply is a derived class of Utilities

/**
 * @brief Creates an instance of WaterSupply utility service.
 * 
 * @return A shared pointer to the created WaterSupply utility.
 */
std::shared_ptr<Utilities> WaterSupplyFactory::createUtilityService() {
    return std::make_shared<WaterSupply>();
}
