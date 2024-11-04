// test/ConcreteFactory_test.cpp
#include "doctest.h"
#include "ConcreteFactory.h"

TEST_CASE("ConcreteFactory creates Concrete resource") {
    ConcreteFactory concreteFactory;
    auto concrete = concreteFactory.createResource(500);

    CHECK(concrete->getName() == "Concrete");
    CHECK(concrete->getQuantity() == 500);
}
