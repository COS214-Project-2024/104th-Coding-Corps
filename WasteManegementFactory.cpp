#include "WasteManagementFactory.h"
#include "wasteManagement.h" // Assuming WasteManagement is a derived class of Utilities

/**
 * @brief Factory method for creating a WasteManagement utility service.
 * 
 * @return A shared pointer to a new WasteManagement utility instance.
 */
std::shared_ptr<Utilities> WasteManagementFactory::createUtilityService() {
    return std::make_shared<WasteManagement>();
}
