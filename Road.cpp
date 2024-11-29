#include "Road.h"

Road::Road(Building* start, Building* end, double length, int capacity, RoadType type) {
	// TODO - implement Road::Road
	throw "Not yet implemented";
}

int Road::getTrafficLevel() {
	return this->trafficLevel;
}

int Road::getLength() {
	// TODO - implement Road::getLength
	throw "Not yet implemented";
}

Building* Road::getStartNode() {
	// TODO - implement Road::getStartNode
	throw "Not yet implemented";
}

Building* Road::getEndNode() {
	// TODO - implement Road::getEndNode
	throw "Not yet implemented";
}

RoadType Road::getRoadType() {
	return this->roadType;
}

double Road::getCondition() {
	return this->condition;
}

bool Road::isCongested() {
	// TODO - implement Road::isCongested
	throw "Not yet implemented";
}

void Road::updateTraffic(int vehicles) {
	// TODO - implement Road::updateTraffic
	throw "Not yet implemented";
}

double Road::calculateCommuteTime() {
	// TODO - implement Road::calculateCommuteTime
	throw "Not yet implemented";
}

void Road::degradeCondition(double amount) {
	// TODO - implement Road::degradeCondition
	throw "Not yet implemented";
}

void Road::repairRoad() {
	// TODO - implement Road::repairRoad
	throw "Not yet implemented";
}

void Road::attach(TrafficManagerInterface* observer) {
	// TODO - implement Road::attach
	throw "Not yet implemented";
}

void Road::detach(TrafficManagerInterface* observer) {
	// TODO - implement Road::detach
	throw "Not yet implemented";
}

void Road::notifyObservers() {
	// TODO - implement Road::notifyObservers
	throw "Not yet implemented";
}

void Road::setTraffic(int newTrafficLevel) {
	// TODO - implement Road::setTraffic
	throw "Not yet implemented";
}
