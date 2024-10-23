#ifndef BUS_H
#define BUS_H

class Bus : PublicTransitStrategy {


public:
	Bus();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
