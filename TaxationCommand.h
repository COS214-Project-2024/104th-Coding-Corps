#ifndef TAXATIONCOMMAND_H
#define TAXATIONCOMMAND_H

class TaxationCommand : Command {

private:
	Citizen2* citizen;
	double taxRate;

public:
	TaxationCommand(Citizen2* c, double rate);

	void execute();
};

#endif
