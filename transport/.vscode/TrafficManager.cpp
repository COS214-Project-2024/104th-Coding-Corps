#include "TrafficManager.h"
#include <utility> 


bool TrafficManager::isCongested(BuildingComponent* from, BuildingComponent* to) {
    auto road = std::make_pair(from, to);

    if (trafficLevels.find(road) == trafficLevels.end()) {
        return false;  
    }

    return trafficLevels[road] > congestionThreshold;
}


void TrafficManager::updateTraffic(BuildingComponent* from, BuildingComponent* to, int trafficLevel) {
   
    trafficLevels[std::make_pair(from, to)] = trafficLevel;
}


void TrafficManager::incrementTraffic(BuildingComponent* from, BuildingComponent* to) {
    auto road = std::make_pair(from, to);


    if (trafficLevels.find(road) == trafficLevels.end()) {
        trafficLevels[road] = 1;
    } else {
      
        trafficLevels[road]++;
    }
}


void TrafficManager::decreaseTraffic(BuildingComponent* from, BuildingComponent* to) {
    auto road = std::make_pair(from, to);


    if (trafficLevels.find(road) != trafficLevels.end() && trafficLevels[road] > 0) {
        trafficLevels[road]--;
    }
}