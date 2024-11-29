#ifndef CITYGRAPH_H
#define CITYGRAPH_H

class CityGraph {

private:
	vector<Buildings*> nodes;
	map<pair<Building*, Building>, null> edges;
	map<pair<Building*, Building*>, null> commuteTimes;

public:
	void addBuilding(Building building);

	void connectBuildings(Building* start, Building* end, Road* road);

	double calculateCommuteTime(Building* from, Building* to);

	vector<Building*> getUnconnectedBuildings();

	bool areBuildingsConnected(Building* from, Building* to);

	Road* getRoadBetween(Building* from, Building* to);

	map<Building*, vector<Building*>> findAllConnectedComponents();
};

#endif
