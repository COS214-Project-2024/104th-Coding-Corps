#include "RailBased.h"

RailBased::RailBased(double speed, std::string mode): TransportStrategy(speed, "Train") {

}

double RailBased::calculateCommuteTime(double distance) {
    
    double baseTime = distance / getSpeed();
    return baseTime * 0.9; 
}