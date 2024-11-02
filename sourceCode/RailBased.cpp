#include "RailBased.h"
/**
 * @brief Constructs a RailBased transportation strategy with a specified speed and sets the mode to "Train."
 * 
 * @param speed The speed of the rail-based transportation mode.
 * @param mode The name of the rail-based transportation mode.
 */
RailBased::RailBased(double speed, std::string mode) : TransportStrategy(speed, "Train") {}

/**
 * @brief Calculates the commute time for rail-based transportation, applying a reduction to the base time.
 * 
 * @param distance The distance to be traveled.
 * @return The total commute time, reduced by 10% for rail-based efficiency.
 */
double RailBased::calculateCommuteTime(double distance) {
    double baseTime = distance / getSpeed();
    return baseTime * 0.9; 
}
