#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

class TrafficManager : TrafficManagerInterface {

public:
	map<Road*, null> roadTrafficData;

	void update(int trafficLevel);

	void recordTrafficData(Road* road, int trafficLevel);

	int getTrafficLevel(Road* road);
};

#endif
