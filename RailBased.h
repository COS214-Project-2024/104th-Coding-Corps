#ifndef RAILBASED_H
#define RAILBASED_H

class RailBased : TransportStrategy {


public:
	RailBased(double speed);

	void calculateCommuteTime(double distance);
};

#endif
