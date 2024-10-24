#ifndef ROAD_H
#define ROAD_H

class Road : RoadInterface {

private:
	double length;
	int trafficLevel;
	int currentTraffic;
	BuildingComponent* startNode;
	BuildingComponent* endNode;
	RoadType roadType;
	double condition;
	vector<TrafficManagerInterface*> observerList;

public:
	Road(Building* start, Building* end, double length, int capacity, RoadType type);

	int getTrafficLevel();

	int getLength();

	Building* getStartNode();

	Building* getEndNode();

	RoadType getRoadType();

	double getCondition();

	bool isCongested();

	void updateTraffic(int vehicles);

	double calculateCommuteTime();

	void degradeCondition(double amount);

	void repairRoad();

	void attach(TrafficManagerInterface* observer);

	void detach(TrafficManagerInterface* observer);

	void notifyObservers();

	void setTraffic(int newTrafficLevel);
};

#endif
