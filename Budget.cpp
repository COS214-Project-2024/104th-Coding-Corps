#include "Budget.h"

Budget::Budget() {
	// TODO - implement Budget::Budget
	throw "Not yet implemented";
}

Budget::Budget(Budget& bug) {
	// TODO - implement Budget::Budget
	throw "Not yet implemented";
}

void Budget::operator=(Budget& bug) {
	// TODO - implement Budget::operator=
	throw "Not yet implemented";
}

Budget* Budget::getInstance() {
	return this->instance;
}

void Budget::addRevenue(double amount) {
	// TODO - implement Budget::addRevenue
	throw "Not yet implemented";
}

bool Budget::deductExpense(double amount) {
	// TODO - implement Budget::deductExpense
	throw "Not yet implemented";
}

double Budget::getBalance() {
	return this->balance;
}
