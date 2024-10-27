#include "WasteManegementFactory.h"
#include "wasteManagement.h"
Utilities* WasteManegementFactory::createUtilityService() {
	return new wasteManagement();
}
