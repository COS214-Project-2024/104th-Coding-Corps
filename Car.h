#ifndef CAR_H
#define CAR_H

class Car {


public:
	Car();

	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);
};

#endif
