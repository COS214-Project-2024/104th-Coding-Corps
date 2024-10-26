#include "Citizen.h"
#include <iostream>

int Citizen::nextID = 10000000; // Initialize static ID counter

/** 
 * @brief Constructs a Citizen with default values.
 */
Citizen::Citizen() : citizenID(nextID++), onStrike(false), employed(true), satisfaction(50) {
    // Additional constructor logic if needed
}

/** 
 * @brief Destroys the Citizen object.
 */
Citizen::~Citizen() {
    // Destructor implementation
}

//-----Citizen stuff-----//

/** 
 * @brief Returns the satisfaction level of the citizen.
 * @return int Satisfaction level of the citizen.
 */
int Citizen::getSatisfaction() const {
    return satisfaction;
}

/** 
 * @brief Returns the expected standard of living.
 * @return int Expected standard of living.
 */
int Citizen::getESoL() const {
    return expectedStandardOfLiving;
}

/** 
 * @brief Returns the actual standard of living.
 * @return int Actual standard of living.
 */
int Citizen::getASoL() const {
    return actualStandardOfLiving;
}

/** 
 * @brief Returns the current income of the citizen.
 * @return double Current income of the citizen.
 */
double Citizen::getCurrentIncome() const {
    return currentIncome;
}

/** 
 * @brief Returns the employment status of the citizen.
 * @return bool Employment status.
 */
bool Citizen::getEmployment() const {
    return employed;
}

/** 
 * @brief Returns the job type of the citizen.
 * @return std::string Job type.
 */
std::string Citizen::getJobType() const {
    return jobType;
}

/** 
 * @brief Sets the job type of the citizen.
 * @param job The job type to be set.
 */
void Citizen::setJobType(const std::string& job) {
    jobType = job;
}

/** 
 * @brief Updates the employment status of the citizen.
 */
void Citizen::updateEmployment() {
    employed = !employed;
}

/** 
 * @brief Updates the citizen's satisfaction by a given amount.
 * @param amount The amount to add to the current satisfaction (can be negative).
 */
void Citizen::updateSatisfaction(int amount) {
    satisfaction += amount;
}

/** 
 * @brief Updates the expected standard of living.
 * @param update The amount to add to the expected standard of living.
 */
void Citizen::updateESoL(int update) {
    expectedStandardOfLiving += update;
}

/** 
 * @brief Updates the actual standard of living.
 * @param update The amount to add to the actual standard of living.
 */
void Citizen::updateASoL(int update) {
    actualStandardOfLiving += update;
}

/** 
 * @brief Updates the current income of the citizen by a given amount.
 * @param amount The amount to add to the current income (can be negative).
 */
void Citizen::updateCurrentIncome(double amount) {
    currentIncome += amount;
}

/** 
 * @brief Increases the education level of the citizen.
 */
void Citizen::increaseEducation() {
    educationLevel++;
}

/** 
 * @brief Promotes the citizen's class based on their current income.
 */
void Citizen::promoteClass() {
    // Promotion logic
}

/** 
 * @brief Demotes the citizen's class based on their current income.
 */
void Citizen::demoteClass() {
    // Demotion logic
}

/** 
 * @brief Puts the citizen on strike, halting work and spending.
 */
void Citizen::goOnStrike() {
    onStrike = true;
}

/** 
 * @brief Resolves the strike, allowing the citizen to resume work and spending.
 */
void Citizen::resolveStrike() {
    onStrike = false;
}

/** 
 * @brief Makes the citizen go to work, affecting satisfaction based on commute.
 */
void Citizen::goToWork() {
    // Travel to work logic
}

/** 
 * @brief Makes the citizen go shopping, affecting satisfaction based on shop quality.
 */
void Citizen::goToShops() {
    // Shopping logic
}

//-----Context Observer-----//

/** 
 * @brief Updates the context of the citizen.
 */
void Citizen::updateContext() {
    // Implementation for context update
}

//-----Composite-----//

/** 
 * @brief Adds a citizen to the composite structure. Not applicable for leaf nodes.
 * @param citizen Shared pointer to the citizen to add.
 */
void Citizen::add(std::shared_ptr<AbstractCitizen> citizen) {
    // Not applicable for leaf node
}

/** 
 * @brief Removes a citizen from the composite structure. Not applicable for leaf nodes.
 * @param citizen Shared pointer to the citizen to remove.
 */
void Citizen::remove(std::shared_ptr<AbstractCitizen> citizen) {
    // Not applicable for leaf node
}

//-----Government: Visitor, Observer-----//

/** 
 * @brief Applies a tax rate to the citizen's income if they are employed.
 * @param taxRate The tax rate to apply.
 */
void Citizen::applyTax(double taxRate) {
    if (employed) {
        currentIncome -= currentIncome * taxRate;
    }
}

/** 
 * @brief Calculates the tax owed by the citizen based on their income.
 * @return double The calculated tax amount.
 */
double Citizen::calculateTax() {
    // Tax calculation logic
    return currentIncome * 0.1; // Example tax rate
}

/** 
 * @brief Deducts a specified tax amount from the citizen's income.
 * @param amount The tax amount to be deducted.
 */
void Citizen::payTax(double amount) {
    currentIncome -= amount;
}

/** 
 * @brief Updates the citizen based on a specific resource type and quantity.
 * @param resourceType Type of resource (e.g., water, food).
 * @param quantity Quantity of the resource affecting the citizen.
 */
void Citizen::update(const std::string& resourceType, int quantity) {
    // Update logic based on resource changes
}
