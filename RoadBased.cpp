#include "RoadBased.h"

// Constructor implementation
RoadBased::RoadBased(double speed, std::string mode) : TransportStrategy(speed, mode) {}


double RoadBased::calculateCommuteTime(double distance) {
   
    double baseTime = distance / getSpeed();
    return baseTime + (distance * 0.1); 
}
