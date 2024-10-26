#include "Government.h"
#include <iostream>

//---------------------------------------------SINGLETON STUFF---------------------------------------------
std::shared_ptr<Government> Government::uniqueInstance = nullptr;
Government::Government() {
    // Initialize resourceManager and budget with the shared pointers returned by their respective Singleton classes
    resourceManager = ResourceManager::getInstance();
    budget = Budget::getInstance();
    
    citizenList = {};
    command = nullptr;
    //std::cout << "Government instance created." << std::endl;
}

std::shared_ptr<Government> Government::getInstance() {
    if (!uniqueInstance) {
        uniqueInstance = std::shared_ptr<Government>(new Government());
    }
    return uniqueInstance;
}
//---------------------------------------------------------------------------------------------------------

//---------------------------------------------COMMAND STUFF----------------------------------------------
void Government::setCommand(Command* c) {
	this->command = c;
}

void Government::issueCommand() {
	if(command) {
		command->execute();
	}
}
//-------------------------------------------------------------------------------------------------------

//----------------------------------------------BUDGET STUFF----------------------------------------------
void Government::increaseBudget(double amount) {
    // Use the budget instance to add revenue
    budget->addRevenue(amount);
}

void Government::decreaseBudget(double amount) {
    // Use the budget instance to deduct an expense
    budget->deductExpense(amount);
}
//--------------------------------------------------------------------------------------------------------

//----------------------------------------------RESOURCE STUFF----------------------------------------------

void Government::notifyResourceChange(std::string resourceType, int quantity) {
    for (auto it = citizenList.begin(); it != citizenList.end(); ++it) {
        if (*it) {
            (*it)->update(resourceType, quantity);  // Notify each citizen of the resource change
        }
    }
}

void Government::addResourceToCity(const std::string& resourceType, int quantity, ResourceFactory& factory) {
    resourceManager->addResource(resourceType, quantity, factory);
    notifyResourceChange(resourceType, quantity);
}

bool Government::useResource(const std::string& type, int quantity) {
    resourceManager->consumeResource(type, quantity);
    int negQuantity = quantity * -1;
    //because we want to notify a negative value (symbolizing consuming)
    notifyResourceChange(type, negQuantity);
}

void Government::displayCityResources() {
	resourceManager->displayResources();
}
//----------------------------------------------------------------------------------------------------------
