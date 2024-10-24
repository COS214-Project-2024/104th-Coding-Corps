#include "TaxationCommand.h"

TaxationCommand::TaxationCommand(AbstractCitizen* c, double rate)
	: citizen(c), taxRate(rate) {}

void TaxationCommand::execute() {
	// TODO - implement TaxationCommand::execute
	citizen->applyTax(taxRate);
}
