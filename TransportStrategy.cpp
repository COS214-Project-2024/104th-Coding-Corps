#include "TransportStrategy.h"
#include <string>

TransportStrategy::TransportStrategy(double speed, std::string mode) {
	speed = speed;
	mode = mode;
}

double TransportStrategy::calculateCommuteTime(double distance)
{
	return distance / speed;
}

std::string TransportStrategy::getMode() {
	return this->mode;
}

double TransportStrategy::getSpeed()
{
    return speed;
}