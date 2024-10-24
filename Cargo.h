#ifndef CARGO_H
#define CARGO_H

class Cargo {


public:
	Cargo();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
