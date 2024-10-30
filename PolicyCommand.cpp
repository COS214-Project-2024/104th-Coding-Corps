#include "PolicyCommand.h"

/**
 * @brief Constructs a PolicyCommand with a specified building and policy type.
 * @param b Pointer to the BuildingComposite on which the policy will be enforced.
 * @param policy The type of policy to enforce.
 */
PolicyCommand::PolicyCommand(BuildingComposite* b, std::string policy) : district(b), policyType(policy) {}

/**
 * @brief Executes the policy command, enforcing the specified policy on the building.
 * @note The `enforcePolicy` method in BuildingComposite is not yet implemented.
 */
void PolicyCommand::execute() {
	district->enforcePolicy(policyType);
	// NB We still need to implement enforcePolicy
}
