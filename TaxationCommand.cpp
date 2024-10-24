#include "TaxationCommand.h"

TaxationCommand::TaxationCommand(std::vector<AbstractCitizen*> c, double rate)
	: citizenList(c), taxRate(rate) {}

void TaxationCommand::execute() {
    // Create a tax collector
    TaxCollector taxCollector;

    // Visit each citizen and collect tax using the visitor pattern
    for (AbstractCitizen* citizen : citizenList) {
        if (citizen) {
            citizen->accept(taxCollector);  // Visitor pattern in action
        }
    }
}
