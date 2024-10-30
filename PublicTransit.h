#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include "TransportStrategy.h"

class PublicTransit : public TransportStrategy {
public:
    PublicTransit(double speed, std::string mode);

   
    double calculateCommuteTime(double distance) override;
};

#endif 
