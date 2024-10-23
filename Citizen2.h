#ifndef CITIZEN2_H
#define CITIZEN2_H

class Citizen2 {

private:
	int satisfaction;
	bool employed;
	int expectedStandardOfLiving;
	int actualStandardOfLiving;
	int educationalLevel;
	ENUM JobType;
	governmentMediator government;
	double currentIncome;
	char district;
	int citizenFName;
	int citizenLName;
	int citizenID;
	Transport* TransportContext;

public:
	void updateContext();

	int getSatisfaction();

	void updateSatisfaction(int update);

	bool getEmployment();

	void updateEmployment();

	int getESoL();

	void updateESoL(int update);

	int getASoL();

	void updateASoL(int update);

	ENUM getJobType();

	void setJobType(ENUM job);

	void add(Citizen2* citizen);

	void remove(Citizen2* citizen);

	void changed();

	void applyTax(double taxRate);

	void travel(BuildingComponent* origin, BuildingComponent* destination);
};

#endif
