#include "Government.h"
#include <iostream>

//---------------------------------------------SINGLETON STUFF---------------------------------------------

/**
 * @brief Unique instance of the Government Singleton.
 */
std::shared_ptr<Government> Government::uniqueInstance = nullptr;

/**
 * @brief Private constructor for the Government Singleton. Initializes the resource manager and budget.
 */
Government::Government() {
    // Initialize resourceManager and budget with the shared pointers returned by their respective Singleton classes
    resourceManager = ResourceManager::getInstance();
    budget = Budget::getInstance();
    
    citizenList = {};
    command = nullptr;
    //std::cout << "Government instance created." << std::endl;
}

/**
 * @brief Gets the singleton instance of the Government class.
 * @return std::shared_ptr<Government> The single instance of Government.
 */
std::shared_ptr<Government> Government::getInstance() {
    if (!uniqueInstance) {
        uniqueInstance = std::shared_ptr<Government>(new Government());
    }
    return uniqueInstance;
}
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------COMMAND STUFF----------------------------------------------

/**
 * @brief Sets the command to be executed by the government.
 * @param c Pointer to the Command object to be executed.
 */
void Government::setCommand(Command* c) {
	this->command = c;
}

/**
 * @brief Issues the command set in the government, if a command is present.
 */
void Government::issueCommand() {
	if(command) {
		command->execute();
	}
}
//-------------------------------------------------------------------------------------------------------

//----------------------------------------------BUDGET STUFF----------------------------------------------

/**
 * @brief Increases the budget by the specified amount.
 * @param amount The amount to add to the budget.
 */
void Government::increaseBudget(double amount) {
    // Use the budget instance to add revenue
    budget->addRevenue(amount);
}

/**
 * @brief Decreases the budget by the specified amount.
 * @param amount The amount to deduct from the budget.
 */
void Government::decreaseBudget(double amount) {
    // Use the budget instance to deduct an expense
    budget->deductExpense(amount);
}
//--------------------------------------------------------------------------------------------------------

//----------------------------------------------RESOURCE STUFF----------------------------------------------

/**
 * @brief Notifies all citizens of a change in a specific resource.
 * @param resourceType The type of resource that has changed.
 * @param quantity The amount by which the resource has changed.
 */
void Government::notifyResourceChange(std::string resourceType, int quantity) {
    for (auto it = citizenList.begin(); it != citizenList.end(); ++it) {
        if (*it) {
            (*it)->update(resourceType, quantity);  // Notify each citizen of the resource change
        }
    }
}

/**
 * @brief Adds a specified quantity of a resource to the city using a resource factory, then notifies citizens.
 * @param resourceType The type of resource to add.
 * @param quantity The amount of the resource to add.
 * @param factory Reference to the ResourceFactory used to create the resource.
 */
void Government::addResourceToCity(const std::string& resourceType, int quantity, ResourceFactory& factory) {
    resourceManager->addResource(resourceType, quantity, factory);
    notifyResourceChange(resourceType, quantity);
}

/**
 * @brief Consumes a specified quantity of a resource from the city and notifies citizens of the reduction.
 * @param type The type of resource to consume.
 * @param quantity The amount of the resource to consume.
 * @return bool True if the resource was successfully consumed, false otherwise.
 */
bool Government::useResource(const std::string& type, int quantity) {
    resourceManager->consumeResource(type, quantity);
    int negQuantity = quantity * -1;
    // Notify citizens of resource consumption with a negative quantity
    notifyResourceChange(type, negQuantity);
}

/**
 * @brief Displays the current resources available in the city.
 */
void Government::displayCityResources() {
	resourceManager->displayResources();
}
//----------------------------------------------------------------------------------------------------------
