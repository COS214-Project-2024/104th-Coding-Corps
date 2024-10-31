#include "ServiceBuildingFactory.h"
#include "School.h"       // Include your specific school implementation
#include "University.h"   // Include your specific university implementation
#include "Hospital.h"     // Include your specific hospital implementation

/**
 * @brief Creates a school building.
 * 
 * @param x The x-coordinate for the school.
 * @param y The y-coordinate for the school.
 * @param district The district name.
 * @param quality The quality rating of the school.
 * @param numWorkers The number of workers in the school.
 * @param highestQualification The highest qualification level of the school.
 * @return A unique pointer to the created school building.
 */
std::unique_ptr<BuildingComponent> ServiceBuildingFactory::createSchool(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification) {
    return std::make_unique<School>(x, y, district, quality, numWorkers, highestQualification);
}

/**
 * @brief Creates a university building.
 * 
 * @param x The x-coordinate for the university.
 * @param y The y-coordinate for the university.
 * @param district The district name.
 * @param quality The quality rating of the university.
 * @param numWorkers The number of workers in the university.
 * @param highestQualification The highest qualification level of the university.
 * @return A unique pointer to the created university building.
 */
std::unique_ptr<BuildingComponent> ServiceBuildingFactory::createUniversity(int x, int y, const std::string& district, int quality, int numWorkers, int highestQualification) {
    return std::make_unique<University>(x, y, district, quality, numWorkers, highestQualification);
}

/**
 * @brief Creates a hospital building.
 * 
 * @param x The x-coordinate for the hospital.
 * @param y The y-coordinate for the hospital.
 * @param district The district name.
 * @param quality The quality rating of the hospital.
 * @param numWorkers The number of workers in the hospital.
 * @return A unique pointer to the created hospital building.
 */
std::unique_ptr<BuildingComponent> ServiceBuildingFactory::createHospital(int x, int y, const std::string& district, int quality, int numWorkers) {
    return std::make_unique<Hospital>(x, y, district, quality, numWorkers);
}
