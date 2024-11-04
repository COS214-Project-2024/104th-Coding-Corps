#ifndef WATERSUPPLYFACTORY_H
#define WATERSUPPLYFACTORY_H

#include "UtilityFactory.h"

class WaterSupplyFactory : public UtilityFactory {

public:
    std::shared_ptr<Utilities> createUtilityService() override;
};

#endif
