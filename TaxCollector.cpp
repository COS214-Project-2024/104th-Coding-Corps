#include "TaxCollector.h"

void TaxCollector::visit(AbstractCitizen& citizen) {
    double taxAmount = citizen.calculateTax(); // Assumes citizens can calculate their own tax
    citizen.payTax(taxAmount);
    //std::cout << "Collected tax of " << taxAmount << " from citizen." << std::endl;
}