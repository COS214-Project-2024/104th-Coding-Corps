#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <memory>

class Resource {
protected:
    int quantity;

public:
    Resource(int quantity) : quantity(quantity) {}
    virtual ~Resource() = default;

    virtual std::string getName() = 0;

    virtual int getQuantity() const;

    virtual void addQuantity(int amount);

    virtual bool consume(int amount);

    virtual bool checkAvailability(int amount) const;
};

#endif // RESOURCE_H