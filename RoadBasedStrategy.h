#ifndef ROADBASEDSTRATEGY_H
#define ROADBASEDSTRATEGY_H

class RoadBasedStrategy {

private:
	double speed;
	int capacity;
	double fuelEfficiency;

public:
	virtual void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph) = 0;

	virtual double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to) = 0;

	void manageTraffic(TrafficManager* trafficManager);

	double getSpeed();

	int getCapacity();

	double getFuelEfficiency();
};

#endif
