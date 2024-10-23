#include "Government.h"

void Government::notify(Citizen2* citizen) {
	// TODO - implement Government::notify
	throw "Not yet implemented";
}

void Government::setCommand(Command* c) {
	this->command = c;
}

void Government::issueCommand() {
	// TODO - implement Government::issueCommand
	throw "Not yet implemented";
}

void Government::notifyResourceChange(string resourceType, int quantity) {
	// TODO - implement Government::notifyResourceChange
	throw "Not yet implemented";
}

void Government::addResourceToCity(string resourceType, int quantity, const ResourceFactory factory) {
	// TODO - implement Government::addResourceToCity
	throw "Not yet implemented";
}

void Government::displayCityResources() {
	// TODO - implement Government::displayCityResources
	throw "Not yet implemented";
}

static Government* Government::instance() {
	// TODO - implement Government::instance
	throw "Not yet implemented";
}

void Government::increaseBudget(double amount) {
	// TODO - implement Government::increaseBudget
	throw "Not yet implemented";
}

void Government::decreaseBudget(double amount) {
	// TODO - implement Government::decreaseBudget
	throw "Not yet implemented";
}
