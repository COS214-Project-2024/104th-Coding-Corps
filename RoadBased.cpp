#include "RoadBased.h"

/**
 * @brief Constructs a RoadBased transportation strategy with a specified speed and mode.
 * 
 * @param speed The speed of the road-based transportation mode.
 * @param mode The name of the road-based transportation mode.
 */
RoadBased::RoadBased(double speed, std::string mode) : TransportStrategy(speed, mode) {}

/**
 * @brief Calculates the commute time for road-based transportation, factoring in an additional time based on distance.
 * 
 * @param distance The distance to be traveled.
 * @return The total commute time, including a road-based adjustment.
 */
double RoadBased::calculateCommuteTime(double distance) {
    double baseTime = distance / getSpeed();
    return baseTime + (distance * 0.1); 
}
