#ifndef RAILBASED_H
#define RAILBASED_H

#include "TransportStrategy.h"

class RailBased : public TransportStrategy {
public:
    RailBased(double speed, std::string mode);


    double calculateCommuteTime(double distance) override;
};

#endif 
