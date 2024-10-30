#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H
#include "Command.h"
#include "AbstractCitizen.h"
#include "TaxCollector.h"
#include <vector>
#include <memory>

class TaxationCommand : public Command {

private:
    std::vector<std::shared_ptr<AbstractCitizen>> citizenList; // Use smart pointers for citizens
    double taxRate;

public:
    TaxationCommand(std::vector<std::shared_ptr<AbstractCitizen>> c, double rate);
    void execute() override;
};

#endif
