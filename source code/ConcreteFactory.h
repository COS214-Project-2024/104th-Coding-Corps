#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H
#include "ResourceFactory.h"
#include "Concrete.h"
#include <memory>

class ConcreteFactory : public ResourceFactory {

public:
    std::unique_ptr<Resource> createResource(int quantity);
};

#endif

