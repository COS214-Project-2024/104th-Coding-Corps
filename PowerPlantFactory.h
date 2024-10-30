#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "UtilityFactory.h"

class PowerPlantFactory : public UtilityFactory {

public:
    std::shared_ptr<Utilities> createUtilityService() override;
};

#endif
