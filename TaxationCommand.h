#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H
#include "Command.h"
#include "AbstractCitizen.h"
#include "TaxCollector.h"
#include <vector>

class TaxationCommand : public Command {

private:
	std::vector<AbstractCitizen*> citizenList;
	double taxRate;

public:
	TaxationCommand(std::vector<AbstractCitizen*> c, double rate);
	void execute();
};

#endif
