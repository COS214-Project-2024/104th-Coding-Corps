#ifndef CITYCONTEXT_H
#define CITYCONTEXT_H

class CityContext {

private:
	float GDP;
	int totalPop;
	int averageStandardOfLiving;
	int averageEducationLevel;
	Citizen* families;

public:
	void attach(Citizen* family);

	void detach(Citizen* family);

	void notify();
};

#endif
