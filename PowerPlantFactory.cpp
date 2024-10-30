#include "PowerPlantFactory.h"
#include "PowerPlant.h"

Utilities* PowerPlantFactory::createUtilityService() {
	return new PowerPlant();
}
