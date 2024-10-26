#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "Command.h"
#include "ResourceManager.h"
#include "ResourceFactory.h"
#include "AbstractCitizen.h"
#include "Budget.h"
#include <string>
#include <vector>


class Government {

private:
	std::vector<AbstractCitizen*> citizenList; 
	Command* command;
	std::shared_ptr<ResourceManager> resourceManager;
	static std::shared_ptr<Government> uniqueInstance;
	std::shared_ptr<Budget> budget;
	Government();

public:
    Government(const Government&) = delete;
    void operator=(const Government&) = delete;
	static std::shared_ptr<Government> getInstance();
	void setCommand(Command* c);
	void issueCommand();
	void notifyResourceChange(std::string resourceType, int quantity);
	void addResourceToCity(const std::string& resourceType, int quantity, ResourceFactory& factory);
	bool useResource(const std::string& type, int quantity);
	void displayCityResources();
	void increaseBudget(double amount);
	void decreaseBudget(double amount);
};

#endif
