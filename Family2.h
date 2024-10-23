#ifndef FAMILY2_H
#define FAMILY2_H

class Family2 : Citizen2 {

private:
	int satisfaction;
	int expectedStandardOfLiving;
	int actualStandardOfLiving;
	double currentIncome;

public:
	citizen* moveDistrict(Citizen2* District);

	void updateContext();

	int getSatisfaction();

	bool getEmployment();

	int getESoL();

	int getASoL();

	void add(Citizen2* citizen);

	void remove(Citizen2* citizen);
};

#endif
