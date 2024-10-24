#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H

class PolicyCommand : Command {

private:
	BuildingComposite* building;
	string policyType;

public:
	PolicyCommand(BuildingComponent* b, string policy);

	void execute();
};

#endif
