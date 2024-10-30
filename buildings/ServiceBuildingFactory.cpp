#include "ServiceBuildingFactory.h"
#include "School.h"
#include "University.h"
#include "Hospital.h"

BuildingComponent* ServiceBuildingFactory::createSchool(int highestQualification, int quality, int numWorkers){
    return new School(highestQualification, quality, numWorkers);
}

BuildingComponent* ServiceBuildingFactory::createUniversity(int highestQualification, int quality, int numWorkers) {
    return new University(highestQualification, quality, numWorkers);
}

BuildingComponent* ServiceBuildingFactory::createHospital(int quality, int numWorkers) {
    return new Hospital(quality, numWorkers);
}