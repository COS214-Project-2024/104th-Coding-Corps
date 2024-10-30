#include "PowerPlantFactory.h"
#include "PowerPlant.h" // Assuming PowerPlant is a derived class of Utilities

std::shared_ptr<Utilities> PowerPlantFactory::createUtilityService() {
    return std::make_shared<PowerPlant>();
}
