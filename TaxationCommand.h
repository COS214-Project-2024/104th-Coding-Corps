#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H
#include "Command.h"
#include "AbstractCitizen.h"

class TaxationCommand : public Command {

private:
	AbstractCitizen* citizen;
	double taxRate;

public:
	TaxationCommand(AbstractCitizen* c, double rate);

	void execute();
};

#endif
