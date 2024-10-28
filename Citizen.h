#ifndef CITIZEN_H
#define CITIZEN_H

#include "AbstractCitizen.h"
#include "CityContext.h"
#include <string>
#include <memory>
#include <random>
#include <ctime>


class Citizen : public AbstractCitizen, public std::enable_shared_from_this<Citizen> {
private:
    int citizenID;
    std::string classType;  // upper, middle, lower
    bool employed;
    int educationLevel;
    std::string jobType;  // Academic, Engineer, Artisan, Doctor, Educator, Retail, LawEnforcement, GovernmentWorker, Farmer
    double monthlyExpenditure;
    bool onStrike;
    static int nextID;
    int x;
    int y;

    // References to other contexts using smart pointers
    std::shared_ptr<void> transportationContext;  // Placeholder for Transport
    std::shared_ptr<void> cityContext;            // Placeholder for CityContext - Observer
    std::shared_ptr<void> government;             // Placeholder for Government - Observer

public:
    //-----Citizen stuff-----//
    Citizen(std::shared_ptr<CityContext> cityContext, std::shared_ptr<Transport> transportContext);
    ~Citizen() override;

    // Getters and setters
    int getSatisfaction() const override;
    int getESoL() const override;
    int getASoL() const override;
    double getCurrentIncome() const override;
    bool getEmployment() const;
    int getEducationLevel() const;
    std::string getJobType() const;
    int getCitizenID() const;
    void setJobType(const std::string& job);
    int getX();
    int getY();
    char getDistrict() const;

    // Updates
    void updateEmployment();
    void updateSatisfaction(int amount);
    void updateESoL(int update);
    void updateASoL(int update);
    void updateCurrentIncome(double amount);
    void updateMonthlyExpenditure(int amount);

    // Additional functionality
    void increaseEducation();
    void promoteClass();
    void demoteClass();
    void goOnStrike() override;
    void resolveStrike() override;
    void goToWork();
    void goToShops();
    void getSchooled();
    void getEducated();
    void getHealed();

    //-----Context Observer-----//
    void updateContext() override;

    //-----Composite-----//
    void add(std::shared_ptr<AbstractCitizen> citizen) override;
    void remove(std::shared_ptr<AbstractCitizen> citizen) override;

    //-----Government: Visitor, Observer-----//
    void applyTax(double taxRate) override;
    double calculateTax() override;
    void payTax(double amount) override;
    void update(const std::string& resourceType, int quantity) override;
    void accept(TaxCollector& collector) override;
};

#endif // CITIZEN_H
