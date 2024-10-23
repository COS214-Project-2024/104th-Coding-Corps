#ifndef FREIGHT_H
#define FREIGHT_H

class Freight {


public:
	Freight();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
