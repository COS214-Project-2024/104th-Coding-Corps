#ifndef GOVERNMENT_H
#define GOVERNMENT_H

class Government : GovernmentMediator {

private:
	Citizen2* citizenList;
	Command* command;
	ResourceManager& resourceManager;
	Government* uniqueInstance;

public:
	void notify(Citizen2* citizen);

	void setCommand(Command* c);

	void issueCommand();

	void notifyResourceChange(string resourceType, int quantity);

	void addResourceToCity(string resourceType, int quantity, const ResourceFactory factory);

	void displayCityResources();

	static Government* instance();

public:
	Government();

	void increaseBudget(double amount);

	void decreaseBudget(double amount);
};

#endif
