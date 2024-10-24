#include "Citizen.h"
#include <iostream>

Citizen::Citizen() : onStrike(false), employed(true), educationLevel(0), monthlyExpenditure(0.0) {
    // Constructor implementation
}

Citizen::~Citizen() {
    // Destructor implementation
}

void Citizen::updateContext() {
    // Implementation
}

int Citizen::getSatisfaction() const {
    return satisfaction;
}

int Citizen::getESoL() const {
    return expectedStandardOfLiving;
}

int Citizen::getASoL() const {
    return actualStandardOfLiving;
}

void Citizen::add(AbstractCitizen* citizen) {
    // Not applicable for leaf node
}

void Citizen::remove(AbstractCitizen* citizen) {
    // Not applicable for leaf node
}

void Citizen::changed() {
    // Implementation for Mediator pattern
}

void Citizen::applyTax(double taxRate) {
    if (employed) {
        currentIncome -= currentIncome * taxRate;
    }
}

void Citizen::update() {
    // Update logic
}

double Citizen::getCurrentIncome() const {
    return currentIncome;
}

void Citizen::goOnStrike() {
    onStrike = true;
    std::cout << citizenFName << " " << citizenLName << " is on strike!" << std::endl;
}

void Citizen::resolveStrike() {
    onStrike = false;
    std::cout << citizenFName << " " << citizenLName << " is back to work!" << std::endl;
}

bool Citizen::getEmployment() const {
    return employed;
}

void Citizen::updateEmployment() {
    employed = !employed;
}

void Citizen::updateSatisfaction(int amount) {
    satisfaction += amount;
}

void Citizen::updateESoL(int update) {
    expectedStandardOfLiving += update;
}

void Citizen::updateASoL(int update) {
    actualStandardOfLiving += update;
}

std::string Citizen::getJobType() const {
    return jobType;
}

void Citizen::setJobType(const std::string& job) {
    jobType = job;
}

void Citizen::increaseEducation() {
    educationLevel++;
}

void Citizen::updateCurrentIncome(double amount) {
    currentIncome += amount;
}

void Citizen::goToWork() {
    // Travel to work logic
}

void Citizen::goToShops() {
    // Shopping logic
}

void Citizen::promoteClass() {
    // Promotion logic
}

void Citizen::demoteClass() {
    // Demotion logic
}
