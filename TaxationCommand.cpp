#include "TaxationCommand.h"

/**
 * @brief Constructs a TaxationCommand with a specified list of citizens and a tax rate.
 * @param c Vector of pointers to AbstractCitizen objects that will be taxed.
 * @param rate The tax rate to apply to each citizen.
 */
TaxationCommand::TaxationCommand(std::vector<AbstractCitizen*> c, double rate)
	: citizenList(c), taxRate(rate) {}

/**
 * @brief Executes the taxation command, using the visitor pattern to apply the tax to each citizen.
 * 
 * Creates a TaxCollector visitor and iterates over each citizen in the list, calling the accept method
 * to apply the tax based on the defined tax rate.
 */
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
