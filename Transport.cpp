#include "Transport.h"
#include "BuildingComponent.h"
#include <math.h>
#include <iostream>

/**
 * @brief Constructs a Transport object and initializes the TrafficManager and the current transportation strategy.
 */
Transport::Transport() {
    trafficManager = std::make_shared<TrafficManager>();
    currentStrategy = nullptr;
}

/**
 * @brief Calculates the Euclidean distance between two buildings.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 * @return The calculated distance between the two buildings.
 */
double Transport::calculateDistance(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    return sqrt(pow(to->getX() - from->getX(), 2) + pow(to->getY() - from->getY(), 2));
}

/**
 * @brief Chooses the appropriate transportation strategy based on the distance and congestion status.
 * 
 * @param distance The distance between two buildings.
 * @param isCongested Indicates if the route between the two buildings is congested.
 */
void Transport::chooseStrategy(double distance, bool isCongested) {
    if (distance <= 1.0) {
        currentStrategy = std::make_shared<RoadBased>(5.0, "Walking");
    } 
    else if (distance > 1.0 && distance <= 10.0) {
        if (isCongested) {
            currentStrategy = std::make_shared<PublicTransit>(40.0, "Bus");
        } else {
            currentStrategy = std::make_shared<RoadBased>(60.0, "Car");
        }
    } 
    else if (distance > 10.0) {
        currentStrategy = std::make_shared<RailBased>(80.0, "Train");
    }
}

/**
 * @brief Completes the travel process by decreasing traffic congestion after travel.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 * @param commuteTime The time taken for the commute.
 * @param mode The transportation mode used for the commute.
 */
void Transport::completeTravel(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to, double commuteTime, const std::string& mode) {
    trafficManager->decreaseTraffic(from, to);
}

/**
 * @brief Initiates travel between two buildings, calculates the distance, chooses the strategy, and manages traffic updates.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 */
void Transport::travel(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    double distance = calculateDistance(from, to);

    bool isCongested = trafficManager->isCongested(from, to);

    chooseStrategy(distance, isCongested);

    double commuteTime = currentStrategy->calculateCommuteTime(distance);

    trafficManager->incrementTraffic(from, to);

    completeTravel(from, to, commuteTime, currentStrategy->getMode());
}
