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
//ask Capleton to explain

void Government::notifyResourceChange(std::string resourceType, int quantity) {
	// TODO - implement Government::notifyResourceChange
	throw "Not yet implemented";
}

void Government::addResourceToCity(std::string resourceType, int quantity, const ResourceFactory factory) {
	// TODO - implement Government::addResourceToCity
	throw "Not yet implemented";
}

void Government::displayCityResources() {
	// TODO - implement Government::displayCityResources
	throw "Not yet implemented";
}
//----------------------------------------------------------------------------------------------------------
