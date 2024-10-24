#ifndef GOVERNMENT_H
#define GOVERNMENT_H
#include "GovernmentMediator.h"
#include "Command.h"
#include "ResourceManager.h"
#include "ResourceFactory.h"
#include "AbstractCitizen.h"
#include <string>


class Government : GovernmentMediator {

private:
	AbstractCitizen* citizenList;
	Command* command;
	ResourceManager& resourceManager;
	Government* uniqueInstance;

public:
	Government();

	static Government* instance();
	
	void notify(AbstractCitizen* citizen);

	void setCommand(Command* c);

	void issueCommand();

	void notifyResourceChange(std::string resourceType, int quantity);

	void addResourceToCity(std::string resourceType, int quantity, const ResourceFactory factory);

	void displayCityResources();

	void increaseBudget(double amount);

	void decreaseBudget(double amount);
};

#endif
