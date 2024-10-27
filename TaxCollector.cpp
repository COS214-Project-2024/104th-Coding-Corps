#include "TaxCollector.h"

/**
 * @brief Visits a citizen to collect tax.
 * 
 * Calculates the tax amount for the citizen using `calculateTax()` and then collects the tax by calling
 * `payTax()` on the citizen.
 * 
 * @param citizen Reference to the AbstractCitizen object on which the tax is collected.
 */
void TaxCollector::visit(AbstractCitizen& citizen) {
    double taxAmount = citizen.calculateTax(); // Assumes citizens can calculate their own tax
    citizen.payTax(taxAmount);
    //std::cout << "Collected tax of " << taxAmount << " from citizen." << std::endl;
}
