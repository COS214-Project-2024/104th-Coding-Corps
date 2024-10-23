#ifndef FAMILY_H
#define FAMILY_H

class Family : Citizen {

private:
	int satisfaction;
	int expectedStandardOfLiving;
	int actualStandardOfLiving;

public:
	Citizen* moveDistrict(Citizen* District);

	virtual void updateContext() = 0;

	int getSatisfaction();

	bool getEmployment();

	int getESoL();

	int getASoL();

	void add(Citizen* citizen);

	void remove(Citizen* citizen);
};

#endif
