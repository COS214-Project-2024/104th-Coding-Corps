#include "TrafficManager.h"
#include <utility> 


bool TrafficManager::isCongested(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) == trafficLevels.end()) {
        return false;  
    }
    return trafficLevels[road] > congestionThreshold;
}


void TrafficManager::updateTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to, int trafficLevel) {
    trafficLevels[std::make_pair(from, to)] = trafficLevel;
}

void TrafficManager::incrementTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) == trafficLevels.end()) {
        trafficLevels[road] = 1;
    } else {
        trafficLevels[road]++;
    }
}

void TrafficManager::decreaseTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to) {
    auto road = std::make_pair(from, to);
    if (trafficLevels.find(road) != trafficLevels.end() && trafficLevels[road] > 0) {
        trafficLevels[road]--;
    }
}