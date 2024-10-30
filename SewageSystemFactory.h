#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "UtilityFactory.h"

class SewageSystemFactory : public UtilityFactory {

public:
    std::shared_ptr<Utilities> createUtilityService() override;
};

#endif
