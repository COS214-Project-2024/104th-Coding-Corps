#include "SewageSystemFactory.h"
#include "sewageManagement.h" // Assuming SewageSystem is a derived class of Utilities

std::shared_ptr<Utilities> SewageSystemFactory::createUtilityService() {
    return std::make_shared<SewageManagement>();
}
