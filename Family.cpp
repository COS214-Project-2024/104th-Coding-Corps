#include "Family.h"
#include <iostream>

/** 
 * @brief Constructs a Family.
 */
Family::Family() {
    // Constructor implementation
}

/** 
 * @brief Destructor for Family.
 */
Family::~Family() {
    // Destructor implementation
}

/** 
 * @brief Adds a citizen to the family.
 * @param citizen Shared pointer to the citizen to add.
 */
void Family::add(std::shared_ptr<AbstractCitizen> citizen) {
    members.push_back(citizen);
}

/** 
 * @brief Removes a citizen from the family.
 * @param citizen Shared pointer to the citizen to remove.
 */
void Family::remove(std::shared_ptr<AbstractCitizen> citizen) {
        auto it = std::find(members.begin(), members.end(), citizen);
    if (it != members.end()) {
        members.erase(it);
    }
}

/** 
 * @brief Returns the average satisfaction of the family.
 * @return int Satisfaction level of the family.
 */
int Family::getSatisfaction() const {
    int totalSatisfaction = 0;
    for (const auto& member : members) {
        totalSatisfaction += member->getSatisfaction();
    }
    satisfaction = members.empty() ? 0 : totalSatisfaction / members.size();
    return satisfaction;

}

/** 
 * @brief Returns the expected standard of living for the family.
 * @return int Expected standard of living.
 */
int Family::getESoL() const {
        int totalESoL = 0;
    for (const auto& member : members) {
        totalESoL += member->getESoL();
    }
    expectedStandardOfLiving = members.empty() ? 0 : totalESoL / members.size();
    return expectedStandardOfLiving;
}

/** 
 * @brief Returns the actual standard of living for the family.
 * @return int Actual standard of living.
 */
int Family::getASoL() const {
        int totalASoL = 0;
    for (const auto& member : members) {
        totalASoL += member->getESoL();
    }
    actualStandardOfLiving = members.empty() ? 0 : totalASoL / members.size();
    return actualStandardOfLiving;
}

/** 
 * @brief Returns the total income of the family.
 * @return double Total income.
 */
double Family::getCurrentIncome() const {
    double totalIncome = 0;
    for (const auto& member : members) {
        totalIncome += member->getCurrentIncome();
    }
    currentIncome =  totalIncome;
    return currentIncome;
}

/** 
 * @brief Puts all members of the family on strike.
 */
void Family::goOnStrike() {
    for (auto& member : members) {
        member->goOnStrike();
    }
}

/** 
 * @brief Resolves strike for all members of the family.
 */
void Family::resolveStrike() {
    for (auto& member : members) {
        member->resolveStrike();
    }
}

/** 
 * @brief Moves the family to a new district.
 * @param district Name of the new district.
 */
void Family::moveDistrict(const std::string& district) {

    this->district = district;
}

/** 
 * @brief Calculates the average monthly expenditure of the family.
 * @return double Average monthly expenditure.
 */
double Family::getMonthlyExpenditure() const {
    double totalExpenditure = 0;
    for (const auto& member : members) {
        totalExpenditure += member->getCurrentIncome() * 0.7; // Assuming 70% of income as expenditure
    }
    return members.empty() ? 0 : totalExpenditure / members.size();
}

/** 
 * @brief Updates the context for all family members.
 */
void Family::updateContext() {
    for (const auto& member : members) {
        member->updateContext();
    }
}

/** 
 * @brief Applies a tax rate to all employed family members.
 * @param taxRate Tax rate to apply.
 */
void Family::applyTax(double taxRate) {
    for (auto& member : members) {
        member->applyTax(taxRate);
    }
}

/** 
 * @brief Calculates the total tax for the family.
 * @return double Total tax amount.
 */
double Family::calculateTax() {
    double totalTax = 0;
    for (const auto& member : members) {
        totalTax += member->calculateTax(); // Each member calculates their own tax
    }
    return totalTax;
}

/** 
 * @brief Pays tax for each family member.
 * @param amount Tax amount to be paid.
 */
void Family::payTax(double amount) {
    for (auto& member : members) {
        member->payTax(amount);
    }
}

/** 
 * @brief Updates the family based on a specific resource change.
 * @param resourceType Type of resource (e.g., water, food).
 * @param quantity Quantity of the resource.
 */
void Family::update(const std::string& resourceType, int quantity) {
    for (auto& member : members) {
        member->update(resourceType, quantity);
    }
}