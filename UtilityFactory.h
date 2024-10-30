#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

#include "Utilities.h"
#include <memory>

class UtilityFactory {

public:
    virtual std::shared_ptr<Utilities> createUtilityService() = 0;
};

#endif
