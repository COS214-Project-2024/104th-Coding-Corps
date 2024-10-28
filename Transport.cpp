#include "Transport.h"
#include "BuildingComponent.h"
#include <math.h>
#include <iostream>


Transport::Transport() {
    trafficManager = new TrafficManager(); 
    currentStrategy = nullptr; 
}

double Transport::calculateDistance(BuildingComponent* from, BuildingComponent* to) {
	return sqrt(pow(to->getX() - from->getX(), 2) + pow(to->getY() - from->getY(), 2));
}

void Transport::chooseStrategy(double distance, bool isCongested) {
    if (distance <= 1.0) {
        currentStrategy = std::shared_ptr<currentStrategy>(new RoadBased(5.0, "Walking")) ;  
    } 
    else if (distance > 1.0 && distance <= 10.0) {
        if (isCongested) {
      
            currentStrategy =  std::shared_ptr<currentStrategy>(new PublicTransit(40.0, "Bus"));
        } else {
            
            currentStrategy =  std::shared_ptr<currentStrategy> (new RoadBased(60.0, "Car"));
        }
    } 
    else if (distance > 10.0) {
        currentStrategy =  std::shared_ptr<currentStrategy>(new RailBased(80.0));  
    }
}

void Transport::completeTravel(BuildingComponent* from, BuildingComponent* to, 
                               double commuteTime, const std::string& mode) {
  
    trafficManager->decreaseTraffic(from, to);

   
    std::cout << "Citizen completed their journey from " << from->getName()
              << " to " << to->getName() << " in " << commuteTime << " hours using " 
              << mode << "." << std::endl;
}


void Transport::travel(BuildingComponent* from, BuildingComponent* to) {
    double distance = calculateDistance(from, to);

   
    bool isCongested = trafficManager->isCongested(from, to);

    chooseStrategy(distance, isCongested);

    double commuteTime = currentStrategy->calculateCommuteTime(distance);

    std::cout << "Citizen travels using " << currentStrategy->getMode()
              << ". Commute time: " << commuteTime << " hours." << std::endl;

    trafficManager->incrementTraffic(from, to);
    completeTravel(from, to, commuteTime, mode);
}