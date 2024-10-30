#include "WaterSupplyFactory.h"
#include "WaterSupply.h" // Assuming WaterSupply is a derived class of Utilities

std::shared_ptr<Utilities> WaterSupplyFactory::createUtilityService() {
    return std::make_shared<WaterSupply>();
}
