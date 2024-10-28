#include "CityContext.h"
#include <iostream>

/** 
 * @brief Constructs a CityContext.
 */
CityContext::CityContext() : GDP(0.0), totalPop(0), averageStandardOfLiving(0.0), averageEducationLevel(0.0), averageIncome(0.0) {
    // Constructor implementation
}

/** 
 * @brief Destructor for CityContext.
 */
CityContext::~CityContext() {
    // Destructor implementation
}

/** 
 * @brief Attaches a citizen to the city's population.
 * @param citizen Shared pointer to the citizen to attach.
 */
// void CityContext::attach(std::shared_ptr<AbstractCitizen> citizen) {
//     int id = citizen->getCitizenID();
//     population[id] = citizen;
// }

// /** 
//  * @brief Detaches a citizen from the city's population.
//  * @param citizen Shared pointer to the citizen to detach.
//  */
// void CityContext::detach(std::shared_ptr<AbstractCitizen> citizen) {
//     int id = citizen->getCitizenID();
//     population.erase(id);
// }

/** 
 * @brief Notifies all citizens of a change in context.
 */
void CityContext::notify() {
    for (auto& [id, citizen] : population) {
        citizen->updateContext();
    }
}
