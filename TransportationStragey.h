#ifndef TRANSPORTATIONSTRAGEY_H
#define TRANSPORTATIONSTRAGEY_H

class TransportationStragey {


public:
	virtual void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph) = 0;

	virtual double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to) = 0;

	virtual void manageTraffic(TrafficManager* trafficManager) = 0;
};

#endif
