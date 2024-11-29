#ifndef FAMILY_H
#define FAMILY_H

#include "AbstractCitizen.h"
#include <vector>

class Family : public AbstractCitizen {
private:
    std::vector<AbstractCitizen*> members;
    void* cityContext;       // Placeholder for CityContext
    void* government;        // Placeholder for Government

public:
    Family();
    ~Family() override;

    // Implemented virtual functions from AbstractCitizen
    void updateContext() override;
    int getSatisfaction() const override;
    int getESoL() const override;
    int getASoL() const override;
    void add(AbstractCitizen* citizen) override;
    void remove(AbstractCitizen* citizen) override;
    void changed() override; // For the Mediator pattern
    void applyTax(double taxRate) override;
    void update() override;
    double getCurrentIncome() const override;
    void goOnStrike() override;
    void resolveStrike() override;

    // Additional functions specific to Family
    void moveDistrict(const std::string& district);
    double getMonthlyExpenditure() const;
};

#endif // FAMILY_H
