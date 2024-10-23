#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport {

private:
	double carSpeed;
	double walkSpeed;
	double trainSpeed;
	double busSpeed;
	TransportStrategy* currentStrategy;

public:
	double calculateDistance(BuildingComponent* from, BuildingComponent* to);

	void chooseStrategy(double distance);

	double calculateCommuteTime(BuildingComponent* from, BuildingComponent* to);

	void travel(BuildingComponent* from, BuildingComponent* to);
};

#endif
