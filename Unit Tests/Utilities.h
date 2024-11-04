#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <memory> // Just to ensure shared_ptr is always recognized

class Utilities {
private:
    std::string utilityType;
    bool active;

public:
    Utilities(std::string type, bool active) : utilityType(type), active(active) {}

    std::string getUtilityType() { return utilityType; }

    virtual double getConsumptionRate() = 0;
    virtual double getCost() = 0;
    virtual void activateUtility() = 0;
    virtual void deactivateUtility() = 0;

    bool getStatus() { return active; }
    void changeStatus(bool status) { active = status; }
};

#endif // UTILITIES_H
