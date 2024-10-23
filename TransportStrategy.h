#ifndef TRANSPORTSTRATEGY_H
#define TRANSPORTSTRATEGY_H

class TransportStrategy {

private:
	double speed;
	string mode;

public:
	TransportStrategy(double speed, string mode);

	virtual double calculateCommuteTime(double distance) = 0;

	string getMode();
};

#endif
