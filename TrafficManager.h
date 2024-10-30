#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include <map>
#include <utility>  
#include "BuildingComponent.h" 
#include <memory>

class TrafficManager {
private:
    std::map<std::pair<std::shared_ptr<BuildingComponent>, std::shared_ptr<BuildingComponent>>, int> trafficLevels;
    const int congestionThreshold = 80;

public:
    TrafficManager() {}

    bool isCongested(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to);
    void updateTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to, int trafficLevel);
    void incrementTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to);
    void decreaseTraffic(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to);
};

#endif
