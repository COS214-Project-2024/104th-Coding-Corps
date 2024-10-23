#ifndef PUBLICTRANSITSTRATEGY_H
#define PUBLICTRANSITSTRATEGY_H

class PublicTransitStrategy {

private:
	int capacity;
	double farePerKm;

public:
	virtual void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph) = 0;

	virtual double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to) = 0;

	void manageTraffic(TrafficManager* trafficManager);
};

#endif
