#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <memory>

class Resource {
protected:
    int quantity;
    double costPerUnit;

public:
    Resource(int initialQuantity, double cost);
    virtual ~Resource() = default;

    virtual std::string getName() = 0;

    virtual int getQuantity() const;

    virtual void addQuantity(int amount);

    virtual bool consume(int amount);

    virtual bool checkAvailability(int amount) const;
    double getCost() const ;
};

#endif // RESOURCE_H