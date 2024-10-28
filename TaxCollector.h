#ifndef TAXCOLLECTOR_H
#define TAXCOLLECTOR_H

#include "Visitor.h"
#include "AbstractCitizen.h"
#include <iostream>

class TaxCollector : public Visitor {
public:
    void visit(AbstractCitizen& citizen) override;
};

#endif
