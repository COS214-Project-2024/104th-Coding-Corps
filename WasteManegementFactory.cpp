#include "WasteManegementFactory.h"
#include "wasteManagement.h" // Assuming WasteManagement is a derived class of Utilities

std::shared_ptr<Utilities> WasteManagementFactory::createUtilityService() {
    return std::make_shared<WasteManagement>();
}
