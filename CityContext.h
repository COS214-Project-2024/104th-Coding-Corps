#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

#include "AbstractCitizen.h"
#include <vector>

class CityContext {
private:
    double GDP;
    int totalPop;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    std::vector<AbstractCitizen*> families;

public:
    CityContext();
    ~CityContext();

    void attach(AbstractCitizen* citizen);
    void detach(AbstractCitizen* citizen);
    void notify();
};

#endif // CITYCONTEXT_H
