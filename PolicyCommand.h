#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H
#include "Command.h"
#include <string>
#include "BuildingComposite.h"

class PolicyCommand : public Command {

private:
	BuildingComposite* building;
	std::string policyType;

public:
	PolicyCommand(BuildingComposite* b, std::string policy);

	void execute();
};

#endif
