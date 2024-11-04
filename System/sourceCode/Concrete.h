#ifndef CONCRETE_H
#define CONCRETE_H

#include "Resource.h"
#include <string>

class Concrete : public Resource {
public:
    Concrete(int quantity, double costPerUnit) : Resource(quantity,costPerUnit) {}

    std::string getName() override;
};

#endif // CONCRETE_H