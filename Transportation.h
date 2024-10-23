#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

class Transportation {

private:
	TransportationStrategy* currentStrategy;
	TrafficManager* trafficData;
	CityGraph* connectivityGraph;

public:
	Transportation(TrafficManager* tm, CityGraph* cg);

	void setStrategy(TransportationStrategy* strategy);

	void monitorAndUpdate();

	double getCommuteTime(Building* from, Building* to);
};

#endif
