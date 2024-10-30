#include "Citizen.h"
#include <iostream>

int Citizen::nextID = 10000000; // static ID counter for citizenID

/**
 * @brief Constructs a Citizen with an initial education level and assigns a job based on that level.
 * @param cityContext Shared pointer to the CityContext for access to city-wide resources.
 * @param transportContext Shared pointer to the Transport system for citizen travel.
 */
Citizen::Citizen(std::shared_ptr<CityContext> cityContext, std::shared_ptr<Transport> transportContext)
    : citizenID(nextID++), onStrike(false), educationLevel(0), cityContext(cityContext), transportationContext(transportContext) {

    satisfaction = 50;
    expectedStandardOfLiving = 50;
    x = 0;
    y = 0;

    // Jobs available at each education level
    static const char* jobsByEducationLevel[][3] = {
        {"ManualLabour", "Retail"},
        {"Farmer", "Artisan", "Educator"},
        {"GovernmentWorker", "LawEnforcement"},
        {"Academic", "Engineer", "Doctor"}
    };

    // Random number generators
    std::mt19937 gen(static_cast<unsigned>(std::time(0)) + citizenID);  // Unique seed per citizen
    std::uniform_int_distribution<> classDist(0, 2);
    std::uniform_int_distribution<> jobDist(0, 1);
    std::uniform_int_distribution<> incomeDist(2000, 5000000);
    std::bernoulli_distribution employmentDist(0.8);  // 80% chance of being employed

    // Assign classType randomly
    int randomClass = classDist(gen);
    classType = (randomClass == 0) ? "upper" : (randomClass == 1) ? "middle" : "lower";

    // Set initial jobType based on educationLevel
    jobType = jobsByEducationLevel[educationLevel][jobDist(gen)];

    // Set employment status
    employed = employmentDist(gen);
    if (employed) {
        currentIncome = incomeDist(gen);
        monthlyExpenditure = currentIncome * 0.7;
    } else {
        currentIncome = 0;
        monthlyExpenditure = 0;
    }

    expectedStandardOfLiving = (classType == "upper") ? 80 : (classType == "middle") ? 50 : 30;
    actualStandardOfLiving = expectedStandardOfLiving;

    //add bro to map of citizens in city context
    cityContext->attach(shared_from_this());

    // Debug print
    std::cout << "Citizen created with ID: " << citizenID << ", Class: " << classType
              << ", Job: " << jobType << ", Education Level: " << educationLevel
              << ", Income: " << currentIncome << ", Monthly Expenditure: " << monthlyExpenditure
              << ", Employed: " << employed << ", Expected SoL: " << expectedStandardOfLiving
              << ", Actual SoL: " << actualStandardOfLiving << std::endl;
}

/** 
 * @brief Destroys the Citizen object.
 */
Citizen::~Citizen() {
    //cityContext->detach(shared_from_this());  // Detaches citizen upon "death"
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
 * @brief Returns the education level of the citizen.
 * @return int education level.
 */
int Citizen::getEducationLevel() const {
    return educationLevel;
}

/** 
 * @brief Returns the job type of the citizen.
 * @return std::string Job type.
 */
std::string Citizen::getJobType() const {
    return jobType;
}

/** 
 * @brief Returns the ID of the citizen.
 * @return int ID
 */
int Citizen::getCitizenID() const {
    return citizenID;
}

/** 
 * @brief Sets the job type of the citizen.
 * @param job The job type to be set.
 */
void Citizen::setJobType(const std::string& job) {
    jobType = job;
}

/**
 * @brief Gets the x-coordinate of the citizen's location.
 * @return int The x-coordinate of the citizen.
 */
int Citizen::getX() const {
    return x;
}

/**
 * @brief Gets the y-coordinate of the citizen's location.
 * @return int The y-coordinate of the citizen.
 */
int Citizen::getY() const {
    return y;
}

/**
 * @brief Gets the district where the citizen resides.
 * @return char The district identifier for the citizen.
 */
std::string Citizen::getDistrict() const {
    return district;
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
    updateMonthlyExpenditure(0.2*amount);
    if(amount > 0){
        updateSatisfaction(2);
        
    if(currentIncome >= 300000 && currentIncome < 1000000 && classType == "lower"){//promoted from lower to middle class
        promoteClass();
    }

    if(currentIncome >= 100000 && classType == "middle"){//promoted from middle to upper
        promoteClass();
    }
    }
    else if(amount < 0){
        updateSatisfaction(-2);
        if(currentIncome < 1000000 && classType == "upper"){
            demoteClass();
        }
        if(currentIncome < 300000 && classType == "middle"){
            demoteClass();
        }
    }
}

/** 
 * @brief Updates the monthlyExpenditure of a citizen
 * @param amount The amount to add to the monthy expenditure (can be negative).
 */
void Citizen::updateMonthlyExpenditure(int amount) {
    monthlyExpenditure += amount;
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
    updateSatisfaction(7);
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
    updateSatisfaction(-8);
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
    updateSatisfaction(20); //ensure they're out of the strike zone
    updateMonthlyExpenditure(1000);//make up for lost monthly expenditure
    onStrike = false;
}

/** 
 * @brief Makes the citizen go to work, slowly this increases their currentIncome to eventually push them into a new class.
 */
void Citizen::goToWork() {
    if(onStrike || !employed){
        return;
    }

    auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Flat");

    if(classType == "middle"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "House");
    }
    else if(classType == "upper"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Estate");
    }

    if (!nearestResidential) {
    std::cout << "No residential available in district for Citizen ID " << citizenID << "." << std::endl;
    updateSatisfaction(-3);
    return;
    }

    auto nearestWorkplace = cityContext->findNearestBuilding(shared_from_this(), "Office");

    if (!nearestWorkplace) {
        std::cout << "No workplace available in district for Citizen ID " << citizenID << "." << std::endl;
        updateSatisfaction(-3);
        return;
    }
    else{
        updateCurrentIncome(90);
        transportationContext->travel(nearestResidential, nearestWorkplace);

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

     auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Flat");

    if(classType == "middle"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "House");
    }
    else if(classType == "upper"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Estate");
    }

    if (!nearestResidential) {
    std::cout << "No residential available in district for Citizen ID " << citizenID << "." << std::endl;
    updateSatisfaction(-3);
    return;
    }

    // Find the nearest shop within the same district
    auto nearestShop = cityContext->findNearestBuilding(shared_from_this(), "Mall");
    if(!nearestShop){ nearestShop = cityContext->findNearestBuilding(shared_from_this(), "Shop");}

    if (!nearestShop) {
        std::cout << "No shop available in district for Citizen ID " << citizenID << "." << std::endl;
        updateSatisfaction(-3);
        return;
    }

    transportationContext->travel(nearestResidential, nearestShop);

    int shopQuality = nearestShop->getQuality(); // Assume `getQuality()` returns an integer (1-100)
    int qualityImpact = (shopQuality / 7);
    if(shopQuality >= 50){
        updateSatisfaction(qualityImpact);
    }
    else{
        updateSatisfaction(-qualityImpact);
    }
   
}

/**
 * @brief Directs the citizen to attend the nearest school/University, increasing their education level if needed.
 *
 * @details Uses the `transportContext` to travel to the nearest school in the citizen's district.
 * If the education level is below 1, it will be set to 1, and the citizen may randomly change their job type.
 */
void Citizen::getSchooled() {
    // Locate nearest school within the citizen's district using Transport class
    auto nearestSchool = cityContext->findNearestBuilding(shared_from_this(), "School");
    if (!nearestSchool) {
        std::cout << "No school available in district!" << std::endl;
        return;
    }

    auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Flat");

    if(classType == "middle"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "House");
    }
    else if(classType == "upper"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Estate");
    }
    if (!nearestResidential) {
    std::cout << "No residential available in district for Citizen ID " << citizenID << "." << std::endl;
    updateSatisfaction(-3);
    return;
    }

    // Use transport to travel to the school
    transportationContext->travel(nearestResidential, nearestSchool);

    // Increase education level if not already 1
    if (educationLevel < 1) {
        educationLevel = 1;
        updateSatisfaction(10);

        // Randomly choose a new job type for the increased education level
        static const char* newJobs[] = {"Farmer", "Artisan", "Educator"};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> jobDist(0, 2);

        jobType = newJobs[jobDist(gen)];

        if(!employed){
            updateEmployment();
            };

        std::cout << "Citizen ID " << citizenID << " attended school, new education level: " 
                  << educationLevel << ", possible new job type: " << jobType << std::endl;
    } else {
        std::cout << "Citizen ID " << citizenID << " already has education level " 
                  << educationLevel << " and did not need additional schooling." << std::endl;
    }
}

/**
 * @brief Makes the citizen go to an educational institution, updating their education level and job opportunities.
 */
void Citizen::getEducated() {

    std::shared_ptr<BuildingComponent> institution = nullptr;

    if(educationLevel == 0){
        return; //cannot attend university before attending school
    } else if (educationLevel == 1 || educationLevel == 2) {
        institution = cityContext->findNearestBuilding(shared_from_this(), "University");
    }

    // Check if the educational institution is available
    if (!institution) {
        std::cout << "No suitable educational institution available in district for Citizen ID " << citizenID << "." << std::endl;
        return;
    }

     auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Flat");

    if(classType == "middle"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "House");
    }
    else if(classType == "upper"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Estate");
    }
    if (!nearestResidential) {
    std::cout << "No residential available in district for Citizen ID " << citizenID << "." << std::endl;
    updateSatisfaction(-3);
    return;
    }

    // Travel to the institution
    transportationContext->travel(nearestResidential, institution);

    // Increase education level according to the type of institution and rules
    if (educationLevel == 1) {
        increaseEducation();  // First university attendance raises level to 2
    } else if (educationLevel == 2) {
        increaseEducation();  // Second university attendance raises level to maximum of 3
    }


    // Adjust job options based on the new education level
    static const char* jobsByEducationLevel[][3] = {
        {"ManualLabour", "Retail"},
        {"Farmer", "Artisan", "Educator"},
        {"GovernmentWorker", "LawEnforcement"},
        {"Academic", "Engineer", "Doctor"}
    };

    // Randomly choose whether to upgrade job or keep the current one
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution jobChangeDist(0.8);  // 50% chance to change job

    if (jobChangeDist(gen) || this->jobType == "ManualLabour" || jobType == "Retail") {
        std::uniform_int_distribution<> jobDist(0, 2);
        jobType = jobsByEducationLevel[educationLevel][jobDist(gen)];
    }
}

/**
 * @brief Makes the citizen travel to the nearest hospital to receive healing, adjusting satisfaction based on hospital quality.
 */
void Citizen::getHealed() {

    auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Flat");

    if(classType == "middle"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "House");
    }
    else if(classType == "upper"){
        auto nearestResidential = cityContext->findNearestBuilding(shared_from_this(), "Estate");
    }
    if (!nearestResidential) {
    std::cout << "No residential available in district for Citizen ID " << citizenID << "." << std::endl;
    updateSatisfaction(-3);
    return;
    }


    // Find the nearest hospital within the citizen's district
    auto nearestHospital = cityContext->findNearestBuilding(shared_from_this(), "Hospital");

    if (!nearestHospital) {
        std::cout << "No hospital available in district for Citizen ID " << citizenID << "." << std::endl;
        updateSatisfaction(-5);
        return;
    }

    // Travel to the hospital
    transportationContext->travel(nearestResidential, nearestHospital);

    // Adjust satisfaction based on hospital quality and commute distance
    int hospitalQuality = nearestHospital->getQuality(); // Assume `getQuality()` returns an integer (1-100)
    int qualityImpact = (hospitalQuality / 7);
    if(hospitalQuality >= 50){
        updateSatisfaction(qualityImpact);
    }
    else{
        updateSatisfaction(-qualityImpact);
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
 * @brief Calculates the tax owed by the citizen based on their income.
 * @return double The calculated tax amount.
 */
double Citizen::calculateTax() {
    if(classType == "lower"){
        return currentIncome * 0.1;
    }
    else if(classType == "middle"){
        return currentIncome * 0.22;
    }
    else if(classType == "upper"){
        return currentIncome * 0.35; //TAX THE RICH AMIRITE BOYS
    }
}

/** 
 * @brief Deducts a specified tax amount from the citizen's income.
 * @param amount The tax amount to be deducted.
 */
void Citizen::payTax(double amount) {
    std::cout << "Paying " << amount << " tax" << std::endl;
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
void Citizen::accept(TaxCollector& collector) {
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

void Citizen::setX(int x) {
    this->x = x;
}

void Citizen::setY(int y) {
    this->y = y;
}