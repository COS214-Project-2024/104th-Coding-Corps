#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "ResourceFactory.h"
#include "Wood.h"

class WoodFactory : public ResourceFactory {
public:
    std::unique_ptr<Resource> createResource(int quantity);
};

#endif // WOODFACTORY_H
