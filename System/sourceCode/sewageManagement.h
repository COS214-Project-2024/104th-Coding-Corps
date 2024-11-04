#ifndef SEWAGEMANAGEMENT_H
#define SEWAGEMANAGEMENT_H

#include "BuildingComponent.h"
#include "string"
using namespace std;

class SewageManagement : public Utilities {


public:
	SewageManagement();

	double getConsumptionRate();

	double getCost();

	void activateUtility();

	void deactivateUtility();

	void manageSewage(BuildingComponent* building);

	std::shared_ptr<Utilities> clone() const override {
        return std::make_shared<SewageManagement>(*this); // Clone implementation
    }
};

#endif
