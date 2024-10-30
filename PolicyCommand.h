#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H
#include "Command.h"
#include <string>
#include "BuildingComposite.h"

class PolicyCommand : public Command {

private:
	BuildingComposite* district;
	std::string policyType;

public:
	PolicyCommand(BuildingComposite* d, std::string policy);
	void execute();
};

#endif
