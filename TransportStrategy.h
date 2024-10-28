#include <string>
#ifndef TRANSPORTSTRATEGY_H
#define TRANSPORTSTRATEGY_H

class TransportStrategy {

private:
	double speed;
	std::string mode;

public:
	TransportStrategy(double speed, std::string mode);

	virtual double calculateCommuteTime(double distance);

	std::string getMode();

	double getSpeed();
	
};

#endif