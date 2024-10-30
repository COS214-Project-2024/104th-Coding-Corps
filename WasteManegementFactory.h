#ifndef WASTEMANEGEMENTFACTORY_H
#define WASTEMANEGEMENTFACTORY_H

#include "UtilityFactory.h"

class WasteManagementFactory : public UtilityFactory {

public:
    std::shared_ptr<Utilities> createUtilityService() override;
};

#endif
