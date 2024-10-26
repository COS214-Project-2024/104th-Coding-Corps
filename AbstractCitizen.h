#ifndef ABSTRACTCITIZEN_H
#define ABSTRACTCITIZEN_H

#include <string>
#include <memory>

class AbstractCitizen {
protected:
    int satisfaction;
    int expectedStandardOfLiving;
    int actualStandardOfLiving;
    double currentIncome;
    std::string district;

public:
    AbstractCitizen();
    virtual ~AbstractCitizen() = default;

    //all will be overridden by subclasses
    virtual void updateContext() = 0;
    virtual int getSatisfaction() const = 0;
    virtual int getESoL() const = 0;
    virtual int getASoL() const = 0;
    virtual void add(std::shared_ptr<AbstractCitizen> citizen) = 0;
    virtual void remove(std::shared_ptr<AbstractCitizen> citizen) = 0;
    virtual void changed() = 0; // For the Mediator pattern
    virtual void applyTax(double taxRate) = 0;
    virtual void update() = 0;
    virtual double getCurrentIncome() const = 0;
    virtual void goOnStrike() = 0;
    virtual void resolveStrike() = 0;
    virtual double calculateTax() = 0;
    virtual void payTax(double amount) = 0;
    virtual void update(const std::string& resourceType, int quantity) = 0;
};

#endif // ABSTRACTCITIZEN_H
