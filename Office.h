#ifndef OFFICE_H
#define OFFICE_H

class Office : CommercialBuildings {

public:
	int numEmployees;

	int getNumEmployees();

	string getBuildingType();

	double getCost();

	double getMaintenanceCost();

	double getEnergyConsumption();

	double getWaterConsumption();

	void construct();

	void demolish();

	string getBusinessType();

	int getNumBusinesses();

	double getArea();
};

#endif
