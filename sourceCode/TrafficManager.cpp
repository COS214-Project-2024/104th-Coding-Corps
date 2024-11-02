#include "TrafficManager.h"
#include <utility> 

/**
 * @brief Checks if the route between two buildings is congested based on current traffic levels.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 * @return True if the route is congested; false otherwise.
 */
bool TrafficManager::isCongested(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) == trafficLevels.end()) {
        return false;  
    }
    return trafficLevels[road] > congestionThreshold;
}

/**
 * @brief Updates the traffic level for a specified route between two buildings.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 * @param trafficLevel The traffic level to set for the route.
 */
void TrafficManager::updateTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to, int trafficLevel) {
    trafficLevels[std::make_pair(from, to)] = trafficLevel;
}

/**
 * @brief Increases the traffic level by one for the specified route between two buildings.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 */
void TrafficManager::incrementTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) == trafficLevels.end()) {
        trafficLevels[road] = 1;
    } else {
        trafficLevels[road]++;
    }
}

/**
 * @brief Decreases the traffic level by one for the specified route between two buildings, ensuring it does not fall below zero.
 * 
 * @param from The starting building component.
 * @param to The destination building component.
 */
void TrafficManager::decreaseTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) != trafficLevels.end() && trafficLevels[road] > 0) {
        trafficLevels[road]--;
    }
}
