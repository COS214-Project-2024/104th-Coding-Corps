#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

#include "Resource.h"
#include <memory>

class ResourceFactory {
public:
    virtual ~ResourceFactory() = default;
    virtual std::unique_ptr<Resource> createResource(int quantity) = 0;
};

#endif // RESOURCEFACTORY_H