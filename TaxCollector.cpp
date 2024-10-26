#include "TaxCollector.h"

void TaxCollector::visit(AbstractCitizen& citizen) {
    double taxAmount = citizen.calculateTax(); // Assumes citizens can calculate their own tax
    citizen.payTax(taxAmount);
    //std::cout << "Collected tax of " << taxAmount << " from citizen." << std::endl;
}



/*
Saber, look here for Citizen.cpp and .h

    void accept(TaxCollector& collector) override {
        collector.visit(*this);
    }

    // Calculate tax based on income
    double calculateTax() const override {
        //However we do that based on income
    }

    // Simulate paying tax
    void payTax(double amount) override {
        std::cout << "Paying tax: " << amount << std::endl;
    }

and for AbstractCitizen.h:

    virtual void accept(TaxCollector& collector) = 0;

    // Other citizen-specific methods (for calculating and paying tax)
    virtual double calculateTax() const = 0;
    virtual void payTax(double amount) = 0;
*/