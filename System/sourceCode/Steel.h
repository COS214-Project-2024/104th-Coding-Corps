#ifndef STEEL_H
#define STEEL_H

#include "Resource.h"
#include <string>

class Steel : public Resource {
public:
    Steel(int quantity, double costPerUnit) : Resource(quantity,costPerUnit) {}

    std::string getName() override;
};

#endif // STEEL_H