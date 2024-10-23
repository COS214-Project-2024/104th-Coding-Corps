#ifndef CITYCONTEXT2_H
#define CITYCONTEXT2_H

class CityContext2 {

private:
	double GDP;
	int totalPop;
	int averageStandardOfLiving;
	int averageEducationLevel;
	Citizen* families;
	double averageIncome;

public:
	void attach(Citizen* citizens);

	void detach(Citizen* citizens);

	void notify();
};

#endif
