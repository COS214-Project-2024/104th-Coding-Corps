#ifndef VISITOR_H
#define VISITOR_H

#include "AbstractCitizen.h"

class Visitor {
public:
    virtual void visit(AbstractCitizen& citizen) = 0;
};

#endif