#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "GovernmentMediator.h"
#include "Command.h"
#include "ResourceManager.h"
#include "ResourceFactory.h"
#include "AbstractCitizen.h"
#include "Budget.h"
#include <string>


class Government : GovernmentMediator {

private:
	AbstractCitizen* citizenList;
	Command* command;
	std::shared_ptr<ResourceManager> resourceManager;
	static std::shared_ptr<Government> uniqueInstance;
	std::shared_ptr<Budget> budget;
	Government();

public:
    Government(const Government&) = delete;
    void operator=(const Government&) = delete;
	static std::shared_ptr<Government> getInstance();
	void notify(AbstractCitizen* citizen);
	void setCitizenList(AbstractCitizen* c);
	void setCommand(Command* c);
	void issueCommand();
	void notifyResourceChange(std::string resourceType, int quantity);
	void addResourceToCity(std::string resourceType, int quantity, const ResourceFactory factory);
	void displayCityResources();
	void increaseBudget(double amount);
	void decreaseBudget(double amount);
};

#endif
