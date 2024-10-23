#ifndef TRUCK_H
#define TRUCK_H

class Truck : RoadBasedStrategy {


public:
	Truck();

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);
};

#endif
