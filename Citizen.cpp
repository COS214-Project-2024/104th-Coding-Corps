#include "Citizen.h"
#include <iostream>

int Citizen::nextID = 10000000; // static ID counter for citizenID

/** 
 * @brief Constructs a Citizen with randomized values.
 */
Citizen::Citizen() : citizenID(nextID++), onStrike(false) {
    satisfaction = 50;
    expectedStandardOfLiving = 50;

    static const char* jobs[] = {
        "ManualLabour", "Academic", "Engineer", "Artisan", "Doctor",
        "Educator", "Retail", "LawEnforcement", "GovernmentWorker", "Farmer"
    };
    static std::mt19937 gen(static_cast<unsigned>(std::time(0)));  // Seed based on the current time
    std::uniform_int_distribution<> classDist(0, 2);
    std::uniform_int_distribution<> jobDist(0, 9);
    std::uniform_int_distribution<> educationDist(0, 3);
    std::uniform_int_distribution<> incomeDist(2000, 5000000);
    std::bernoulli_distribution employmentDist(0.8);  // 80% chance of being employed
    const int numJobs = sizeof(jobs) / sizeof(jobs[0]);
    std::uniform_int_distribution<> jobDist(0, numJobs - 1);

    // Assign classType randomly with 1/3 probability each
    int randomClass = classDist(gen);
    switch (randomClass) {
        case 0:
            classType = "upper";
            break;
        case 1:
            classType = "middle";
            break;
        case 2:
            classType = "lower";
            break;
    }

    // Randomly assign JobType
    jobType = jobs[jobDist(gen)];

        // Randomly set employed status
    employed = employmentDist(gen);

    // Randomly assign educationLevel (0 to 3)
    educationLevel = educationDist(gen);

    if(employed){
    // Randomly assign currentIncome within bounds
    currentIncome = incomeDist(gen);
    // Calculate monthlyExpenditure as 70% of currentIncome
    monthlyExpenditure = currentIncome * 0.7;
    }
    else{
        currentIncome = 0;
        monthlyExpenditure = 0;
    }
   
    // Initialize expectedStandardOfLiving and actualStandardOfLiving
    expectedStandardOfLiving = classType == "upper" ? 80 : (classType == "middle" ? 50 : 30);
    actualStandardOfLiving = expectedStandardOfLiving;

    // Optionally, print for debugging
    std::cout << "Citizen created with ID: " << citizenID << ", Class: " << classType 
              << ", Job: " << jobType
              << ", Education Level: " << educationLevel
              << ", Income: " << currentIncome
              << ", Monthly Expenditure: " << monthlyExpenditure
              << ", Employed: " << employed
              << ", Expected Standard of Living: " << expectedStandardOfLiving 
              << ", Actual Standard of Living: " << actualStandardOfLiving << std::endl;
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

    if(!employed){//just lost employment
        this->updateSatisfaction(-5);
        //update currentIncome nased on jobType
        if(jobType == "Manual Labour"){
            updateCurrentIncome(-18000);
        }
        else if(jobType == "Academic"){
            updateCurrentIncome(-40000);
        }
        else if(jobType == "Engineer"){
            updateCurrentIncome(-90000);
        }
        else if(jobType == "Artisan"){
            updateCurrentIncome(-35000);
        }
        else if(jobType == "Doctor"){
            updateCurrentIncome(-95000);
        }
        else if(jobType == "Retail"){
            updateCurrentIncome(-10000);
        }
        else if(jobType == "LawEnforcement"){
            updateCurrentIncome(-25000);
        }
        else if(jobType == "GovernmentWorker"){
            updateCurrentIncome(-10000);
        }
        else if(jobType == "Farmer"){
            updateCurrentIncome(-35000);
        }
        else if(jobType == "Educator"){
            updateCurrentIncome(-27000);
        }
    }
    else if(employed){//just became emplyed
        this->updateSatisfaction(5);
        //update currentIncome depending on jobType
        if(jobType == "Manual Labour"){
            updateCurrentIncome(18000);
        }
        else if(jobType == "Academic"){
            updateCurrentIncome(40000);
        }
        else if(jobType == "Engineer"){
            updateCurrentIncome(90000);
        }
        else if(jobType == "Artisan"){
            updateCurrentIncome(35000);
        }
        else if(jobType == "Doctor"){
            updateCurrentIncome(95000);
        }
        else if(jobType == "Retail"){
            updateCurrentIncome(10000);
        }
        else if(jobType == "LawEnforcement"){
            updateCurrentIncome(25000);
        }
        else if(jobType == "GovernmentWorker"){
            updateCurrentIncome(10000);
        }
        else if(jobType == "Farmer"){
            updateCurrentIncome(35000);
        }
        else if(jobType == "Educator"){
            updateCurrentIncome(27000);
        }
    }
    
}

/** 
 * @brief Updates the citizen's satisfaction by a given amount.
 * @param amount The amount to add to the current satisfaction (can be negative).
 */
void Citizen::updateSatisfaction(int amount) {
    satisfaction += amount;
    //keep it within bounds
    if(satisfaction < 0 && !onStrike){
        satisfaction = 0;
        this->goOnStrike();
    }
    else if(satisfaction > 100){
        satisfaction = 100;
    }
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
    //SoL affects citizen satisfaction
    updateSatisfaction(update*0.5);

}

/** 
 * @brief Updates the current income of the citizen by a given amount.
 * @param amount The amount to add to the current income (can be negative).
 */
void Citizen::updateCurrentIncome(double amount) {
    currentIncome += amount;
    if(amount > 0){
        updateSatisfaction(5);
        
    if(currentIncome >= 300000 && currentIncome < 1000000 && classType == "lower"){//promoted from lower to middle class
        promoteClass();
    }

    if(currentIncome >= 100000 && classType == "middle"){//promoted from middle to upper
        promoteClass();
    }
    }
    else if(amount < 0){
        updateSatisfaction(-5);
        if(currentIncome < 1000000 && classType == "upper"){
            demoteClass();
        }
        if(currentIncome < 300000 && classType == "middle"){
            demoteClass();
        }
    }


}

/** 
 * @brief Increases the education level of the citizen.
 */
void Citizen::increaseEducation() {
    educationLevel++;
    updateSatisfaction(10);
}

/** 
 * @brief Promotes the citizen's class based on their current income.
 */
void Citizen::promoteClass() {
    if(classType == "lower"){
        classType = "middle";
        updateESoL(15);
    }
    else if(classType == "middle"){
        classType = "upper";
        updateESoL(20);
    }
}

/** 
 * @brief Demotes the citizen's class based on their current income.
 */
void Citizen::demoteClass() {
        if(classType == "middle"){
        classType = "lower";
        updateESoL(-20);
    }
    else if(classType == "upper"){
        classType = "middle";
        updateESoL(-15);
    }
}

/** 
 * @brief Puts the citizen on strike, halting work and spending.
 */
void Citizen::goOnStrike(){
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
    if(onStrike){
        return;
    }
}

/** 
 * @brief Makes the citizen go shopping, affecting satisfaction based on shop quality.
 */
void Citizen::goToShops() {
   if(onStrike){
    monthlyExpenditure -= 1000;
    return;
   }
}

//-----Context Observer-----//

/** 
 * @brief Updates the context of the citizen.
 */
void Citizen::updateContext() {
    // Implementation for context update
    //guess i got nothing rn
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
    if(classTpe == "lower"){
        return currentIncome * 0.1;
    }
    else if(classType == "middle"){
        return currentIncome * 0.22;
    }
    else if(classType == "upper"){
        return currentIncome 0.35; //TAX THE RICH AMIRITE BOYS
    }
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
    double adjustmentFactor = 0.05; // e.g., 5% of the quantity change impacts satisfaction
    updateSatisfaction(quantity * adjustmentFactor);
}

/**
 * @brief Accepts a TaxCollector visitor, allowing it to interact with this Citizen.
 *
 * This function is part of the Visitor pattern, enabling a `TaxCollector` object
 * to perform operations on this `Citizen` instance. The `TaxCollector` can access
 * the citizen's data and apply taxes or other related actions.
 *
 * @param collector A reference to the `TaxCollector` visitor.
 */
void Citizen::accept(TaxCollector& collector) override {
    collector.visit(*this);
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