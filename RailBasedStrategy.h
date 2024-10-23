#ifndef RAILBASEDSTRATEGY_H
#define RAILBASEDSTRATEGY_H

class RailBasedStrategy : TransportationStragey {

private:
	double speed;
	double capacity;
	double costPerKm;

public:
	virtual void planRoute(TrafficManager* trafficManager, CityGraph* cityGraph) = 0;

	virtual double calculateCommuteTime(CityGraph* cityGraph, Building* from, Building* to) = 0;

	void manageTraffic(TrafficManager* trafficManager);

	double getSpeed();

	double getCapacity();

	double getCostPerKm();
};

#endif
