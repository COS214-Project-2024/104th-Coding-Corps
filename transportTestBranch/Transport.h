#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "TransportStrategy.h"
#include "RoadBased.h"
#include "RailBased.h"
#include "PublicTransit.h"
#include "TrafficManager.h"
#include "BuildingComponent.h"
#include <memory>

class Transport {
private:
    double carSpeed = 60.0;
    double walkSpeed = 5.0;
    double trainSpeed = 80.0;
    double busSpeed = 40.0;
    std::shared_ptr<TransportStrategy> currentStrategy;
    std::shared_ptr<TrafficManager> trafficManager;

public:
    Transport();  
    
    double calculateDistance(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to);
    void chooseStrategy(double distance, bool isCongested);
    void travel(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to);
    void completeTravel(std::shared_ptr<BuildingComponent> from, std::shared_ptr<BuildingComponent> to, double commuteTime, const std::string& mode);
};

#endif
