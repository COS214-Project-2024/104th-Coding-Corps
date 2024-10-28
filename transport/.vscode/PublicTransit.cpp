#include "PublicTransit.h"
#include <string>


    PublicTransit::PublicTransit(double speed, std::string mode) : TransportStrategy(speed, mode) {}

    
    double PublicTransit::calculateCommuteTime(double distance) {
        
        double baseTime = distance / getSpeed();
        return baseTime + 15.0; 
    }