
#ifndef WOOD_H
#define WOOD_H

#include "Resource.h"
#include <string>

class Wood : public Resource {
public:
    Wood(int quantity, double costPerUnit) : Resource(quantity,costPerUnit) {}

    std::string getName() override;
};

#endif // WOOD_H