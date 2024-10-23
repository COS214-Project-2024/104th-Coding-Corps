#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen {

private:
	int satisfaction;
	bool employed;
	int expectedStandardOfLiving;
	int ActualStandardOfLiving;
	int educationLevel;
	ENUM JobType;
	GovernmentMediator government;
	double currentIncome;
	char district;

public:
	virtual void updateContext() = 0;

	int getSatisfaction();

	void updateSatisfaction(int amount);

	bool getEmployment();

	void updateEmployment();

	int getESoL();

	void updateESoL(int update);

	int getASoL();

	void updateASoL(int update);

	ENUM getJobType();

	void setJobType(ENUM job);

	void add(Citizen* citizen);

	void remove(Citizen* citizen);

	void changed();

	void applyTax(double taxRate);
};

#endif
