
#ifndef WOOD_H
#define WOOD_H

#include "Resource.h"
#include <string>

class Wood : public Resource {
public:
    Wood(int quantity) : Resource(quantity) {}

    std::string getName() override;
};

#endif // WOOD_H