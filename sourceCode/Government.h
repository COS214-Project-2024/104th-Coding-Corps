#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Command.h"
#include "ResourceManager.h"
#include "ResourceFactory.h"
#include "AbstractCitizen.h"
#include "Budget.h"
#include <string>
#include <vector>
#include <memory>

class Government {

private:
    std::vector<std::shared_ptr<AbstractCitizen>> citizenList; // Use smart pointers for citizens
    std::shared_ptr<Command> command;                           // Use a smart pointer for the command
    std::shared_ptr<ResourceManager> resourceManager;
    static std::shared_ptr<Government> uniqueInstance;
    std::shared_ptr<Budget> budget;
    Government();
    std::string currentTaxRatePolicy = "standard";

public:
    Government(const Government&) = delete;
    void operator=(const Government&) = delete;
    static std::shared_ptr<Government> getInstance();
    void setCommand(const std::shared_ptr<Command>& c);        // Accept shared pointer for command
    void issueCommand();
    void notifyResourceChange(const std::string& resourceType, int quantity);
    void addResourceToCity(const std::string& resourceType, int quantity,double costPerUnit, ResourceFactory& factory);
    bool useResource(const std::string& type, int quantity);
    void displayCityResources();
    void increaseBudget(double amount);
    void decreaseBudget(double amount);
    double getBalance() const;
    void printTransactionHistory() const;
    void setTaxRatePolicy(const std::string& taxRatePolicy);
    std::string getTaxRatePolicy() const;
    bool deductExpense(double amount);
};

#endif
