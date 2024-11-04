#include "PowerPlantFactory.h"
#include "PowerPlant.h" // Assuming PowerPlant is a derived class of Utilities

/**
 * @brief Creates a utility service of type PowerPlant.
 * 
 * This method instantiates a new PowerPlant object and returns it as a shared pointer 
 * to the Utilities base class.
 * 
 * @return A shared pointer to a Utilities object representing the PowerPlant.
 */
std::shared_ptr<Utilities> PowerPlantFactory::createUtilityService() {
    return std::make_shared<PowerPlant>();
}
