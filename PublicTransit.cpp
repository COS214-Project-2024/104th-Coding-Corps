#include "PublicTransit.h"
#include <string>


    /**
 * @brief Constructs a PublicTransit transportation strategy with a specified speed and mode.
 * 
 * @param speed The speed of the public transit mode.
 * @param mode The name of the public transit mode.
 */
PublicTransit::PublicTransit(double speed, std::string mode) : TransportStrategy(speed, mode) {}

/**
 * @brief Calculates the commute time for public transit, adding a fixed delay to the base time.
 * 
 * @param distance The distance to be traveled.
 * @return The total commute time, including a fixed public transit delay.
 */
double PublicTransit::calculateCommuteTime(double distance) {
    double baseTime = distance / getSpeed();
    return baseTime + 15.0; 
}
