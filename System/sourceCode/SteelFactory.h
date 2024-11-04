#ifndef STEELFACTORY_H
#define STEELFACTORY_H

#include "ResourceFactory.h"
#include "Steel.h"

class SteelFactory : public ResourceFactory {
public:
    std::unique_ptr<Resource> createResource(int quantity, double costPerUnit);
};

#endif // STEELFACTORY_H