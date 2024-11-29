#ifndef CITIZEN_H
#define CITIZEN_H

#include "AbstractCitizen.h"
#include <string>

class Citizen : public AbstractCitizen {
private:
    std::string citizenFName;
    std::string citizenLName;
    std::string citizenID;
    std::string classType;  // "upper", "middle", "lower"
    bool employed;
    int educationLevel;
    std::string jobType;
    double monthlyExpenditure;
    bool onStrike;
    // References to other contexts
    void* transportContext;  // Placeholder for Transport
    void* cityContext;       // Placeholder for CityContext
    void* government;        // Placeholder for Government

public:
    Citizen();
    ~Citizen() override;

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

    // Additional functions specific to Citizen
    bool getEmployment() const;
    void updateEmployment();
    void updateSatisfaction(int amount);
    void updateESoL(int update);
    void updateASoL(int update);
    std::string getJobType() const;
    void setJobType(const std::string& job);
    void increaseEducation();
    void updateCurrentIncome(double amount);
    void goToWork();
    void goToShops();
    void promoteClass();
    void demoteClass();
};

#endif // CITIZEN_H
