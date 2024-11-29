#ifndef CYCLE_H
#define CYCLE_H

class Cycle {


public:
	Cycle();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
