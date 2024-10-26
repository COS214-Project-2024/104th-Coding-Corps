#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

#include "AbstractCitizen.h"
#include <map>
#include <memory>

class CityContext {
private:
    double GDP;
    int totalPop;
    double averageStandardOfLiving;
    double averageEducationLevel;
    double averageIncome;
    std::map<int, std::shared_ptr<Citizen>> population;

public:
    CityContext();
    ~CityContext();

    void attach(std::shared_ptr<AbstractCitizen> citizen);
    void detach(std::shared_ptr<AbstractCitizen> citizen);
    void notify();
};

#endif // CITYCONTEXT_H
