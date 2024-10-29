#include "WaterSupplyFactory.h"
#include "WaterSupply.h"

Utilities* WaterSupplyFactory::createUtilityService() {
	return new WaterSupply();
}
