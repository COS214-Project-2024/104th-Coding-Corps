#ifndef TAXI_H
#define TAXI_H

class Taxi : PublicTransitStrategy {


public:
	Taxi();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
