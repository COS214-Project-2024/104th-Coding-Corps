#include "CityContext.h"
#include <iostream>

CityContext::CityContext() : GDP(0.0), totalPop(0), averageStandardOfLiving(0.0), averageEducationLevel(0.0), averageIncome(0.0) {
    // Constructor implementation
}

CityContext::~CityContext() {
    // Destructor implementation
}

void CityContext::attach(AbstractCitizen* citizen) {
    families.push_back(citizen);
}

void CityContext::detach(AbstractCitizen* citizen) {
    // Remove citizen from observers
}

void CityContext::notify() {
    for (auto* citizen : families) {
        citizen->updateContext();
    }
}
