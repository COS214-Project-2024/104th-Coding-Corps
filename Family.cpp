#include "Family.h"
#include <iostream>

Family::Family() {
    // Constructor implementation
}

Family::~Family() {
    // Destructor implementation
}

void Family::updateContext() {
    for (auto* member : members) {
        member->updateContext();
    }
}

int Family::getSatisfaction() const {
    // Calculate average satisfaction
    return 0;  // Placeholder
}

int Family::getESoL() const {
    return expectedStandardOfLiving;
}

int Family::getASoL() const {
    return actualStandardOfLiving;
}

void Family::add(AbstractCitizen* citizen) {
    members.push_back(citizen);
}

void Family::remove(AbstractCitizen* citizen) {
    // Remove citizen from family
}

void Family::changed() {
    // Implementation for Mediator pattern
}

void Family::applyTax(double taxRate) {
    for (auto* member : members) {
        member->applyTax(taxRate);
    }
}

void Family::update() {
    for (auto* member : members) {
        member->update();
    }
}

double Family::getCurrentIncome() const {
    double totalIncome = 0;
    for (const auto* member : members) {
        totalIncome += member->getCurrentIncome();
    }
    return totalIncome;
}

void Family::goOnStrike() {
    for (auto* member : members) {
        member->goOnStrike();
    }
}

void Family::resolveStrike() {
    for (auto* member : members) {
        member->resolveStrike();
    }
}

void Family::moveDistrict(const std::string& district) {
    this->district = district;
}

double Family::getMonthlyExpenditure() const {
    // Calculate average expenditure
    return 0;  // Placeholder
}
