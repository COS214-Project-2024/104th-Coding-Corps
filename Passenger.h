#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger : RailBasedStrategy {


public:
	Passenger();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
