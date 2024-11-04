#include "TransportStrategy.h"
#include <string>
#include <iostream>
/**
 * @brief Constructs a TransportStrategy with a specified speed and mode of transportation.
 * 
 * @param speed The speed of the transportation mode.
 * @param mode The name of the transportation mode.
 */
TransportStrategy::TransportStrategy(double speed, std::string mode) {
    this->speed = speed;
    this->mode = mode;
}

/**
 * @brief Calculates the commute time based on distance and the strategy's speed.
 * 
 * @param distance The distance to be traveled.
 * @return The time required to complete the commute.
 */
double TransportStrategy::calculateCommuteTime(double distance) {
    std::cout << "Current mode= " << this->mode << " Distance= " << distance << " Speed= " << this->speed << std::endl;
    return distance / speed;
}

/**
 * @brief Retrieves the mode of transportation for this strategy.
 * 
 * @return The mode of transportation as a string.
 */
std::string TransportStrategy::getMode() {
    return this->mode;
}

/**
 * @brief Retrieves the speed of this transportation strategy.
 * 
 * @return The speed of the transportation mode.
 */
double TransportStrategy::getSpeed() {
    return speed;
}
