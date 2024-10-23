#ifndef LOWERCLASSCITIZEN2_H
#define LOWERCLASSCITIZEN2_H

class LowerclassCitizen2 : Citizen2 {

private:
	int satisfaction;
	bool employed;
	int expectedStandardOfLiving;
	int actualStandardOfLiving;
	int educationLevel;
	ENUM JobType;
	double currentIncome;
	char district;
	int citizenFName;
	int citizenLName;
	int citizenID;

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

	void changed();

	void applyTax(double taxRate);
};

#endif
