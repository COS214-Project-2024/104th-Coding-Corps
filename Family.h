#ifndef FAMILY_H
#define FAMILY_H

#include "AbstractCitizen.h"
#include <vector>
#include <memory>
#include <iostream>

class Family : public AbstractCitizen {
private:
    std::vector<std::shared_ptr<AbstractCitizen>> members;
    std::shared_ptr<void> cityContext;
    std::shared_ptr<void> government;

public:
//-----Family Composite stuff-----//
    Family();
    ~Family() override;
    void add(std::shared_ptr<AbstractCitizen> citizen) override;
    void remove(std::shared_ptr<AbstractCitizen> citizen) override;
    
    int getSatisfaction() const override;
    int getESoL() const override;
    int getASoL() const override;
    double getCurrentIncome() const override;
    
    void goOnStrike() override;
    void resolveStrike() override;
    void moveDistrict(const std::string& district);
    double getMonthlyExpenditure() const;

//-----Context Observer-----//
    void updateContext() override;
 
//-----Government: Observer, Visitor-----//
    void applyTax(double taxRate) override;
    double calculateTax() override;
    void payTax(double amount) override;
    void update(const std::string& resourceType, int quantity) override;
    void accept(TaxCollector& collector) override;

};

#endif // FAMILY_H
