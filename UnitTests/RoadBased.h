#ifndef ROADBASED_H
#define ROADBASED_H

#include "TransportStrategy.h"

class RoadBased : public TransportStrategy {
public:
    RoadBased(double speed, std::string mode);


    double calculateCommuteTime(double distance) override;
};

#endif 
