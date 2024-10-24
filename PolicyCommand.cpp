#include "PolicyCommand.h"

PolicyCommand::PolicyCommand(BuildingComposite* b, std::string policy) : district(d), policyType(policy) {}

void PolicyCommand::execute() {
	district->enforcePolicy(policyType);
}
