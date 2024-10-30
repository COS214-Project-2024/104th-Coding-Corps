#ifndef POLICYCOMMAND_H
#define POLICYCOMMAND_H
#include "Command.h"
#include <string>
#include <memory>
#include "BuildingComposite.h"
#include "Government.h"

class PolicyCommand : public Command {

private:
	std::shared_ptr<BuildingComposite> district;
    std::string policyType;  // Key of the policy to update
    std::string updatedValue;  // New value for the policy
	std::shared_ptr<Government> government; 

public:
	PolicyCommand(std::shared_ptr<BuildingComposite> district, std::shared_ptr<Government> government, const std::string& policyType, const std::string& updatedValue);
	void execute();
};

#endif
