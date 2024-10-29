#include "SewageSystemFactory.h"
#include "sewageManagement.h"

Utilities* SewageSystemFactory::createUtilityService() {
	return new sewageManagement();
}
