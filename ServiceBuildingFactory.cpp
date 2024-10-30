#include "ServiceBuildingFactory.h"
#include "School.h"       // Include your specific school implementation
#include "University.h"   // Include your specific university implementation
#include "Hospital.h"     // Include your specific hospital implementation

/**
 * @brief Creates a school building.
 * 
 * @param highestQualification The highest qualification level of the school.
 * @param quality The quality rating of the school.
 * @param numWorkers The number of workers in the school.
 * @return A shared pointer to the created school building.
 */
std::shared_ptr<BuildingComponent> ServiceBuildingFactory::createSchool(int highestQualification, int quality, int numWorkers) {
    return std::make_shared<School>(highestQualification, quality, numWorkers);
}

/**
 * @brief Creates a university building.
 * 
 * @param highestQualification The highest qualification level of the university.
 * @param quality The quality rating of the university.
 * @param numWorkers The number of workers in the university.
 * @return A shared pointer to the created university building.
 */
std::shared_ptr<BuildingComponent> ServiceBuildingFactory::createUniversity(int highestQualification, int quality, int numWorkers) {
    return std::make_shared<University>(highestQualification, quality, numWorkers);
}

/**
 * @brief Creates a hospital building.
 * 
 * @param quality The quality rating of the hospital.
 * @param numWorkers The number of workers in the hospital.
 * @return A shared pointer to the created hospital building.
 */
std::shared_ptr<BuildingComponent> ServiceBuildingFactory::createHospital(int quality, int numWorkers) {
    return std::make_shared<Hospital>(quality, numWorkers);
}
