#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include <map>
#include <utility>  
#include "BuildingComponent.h" 

class TrafficManager {
private:

    std::map<std::pair<BuildingComponent*, BuildingComponent*>, int> trafficLevels;

    const int congestionThreshold = 80;

public:
   
    TrafficManager() {}

    bool isCongested(BuildingComponent* from, BuildingComponent* to);

    void updateTraffic(BuildingComponent* from, BuildingComponent* to, int trafficLevel);

    void incrementTraffic(BuildingComponent* from, BuildingComponent* to);

    void decreaseTraffic(BuildingComponent* from, BuildingComponent* to);
};

#endif 