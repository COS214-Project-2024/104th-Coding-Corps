#ifndef AIRTRAVELSTRATEGY_H
#define AIRTRAVELSTRATEGY_H

class AirTravelStrategy {


public:
	void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph);

	double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to);

	void manageTraffic(TrafficManager* trafficManager);
};

#endif
