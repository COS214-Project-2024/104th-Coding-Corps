#include "SewageSystemFactory.h"
#include "sewageManagement.h" // Assuming SewageManagement is a derived class of Utilities

/**
 * @brief Creates a new instance of the SewageManagement utility.
 * 
 * This factory method instantiates a shared pointer to a 
 * SewageManagement object, which is a specific type of utility 
 * service.
 * 
 * @return A shared pointer to a newly created SewageManagement instance.
 */
std::shared_ptr<Utilities> SewageSystemFactory::createUtilityService() {
    return std::make_shared<SewageManagement>();
}
