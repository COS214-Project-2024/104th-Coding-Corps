// test/ResourceManager_test.cpp
#include "doctest.h"
#include "ResourceManager.h"
#include "ConcreteFactory.h"
#include "SteelFactory.h"

TEST_CASE("ResourceManager Singleton and Resource Handling") {
    auto resourceManager = ResourceManager::getInstance();
    ConcreteFactory concreteFactory;
    SteelFactory steelFactory;

    resourceManager->addResource("Concrete", 500, concreteFactory);
    resourceManager->addResource("Steel", 300, steelFactory);

    CHECK(resourceManager->isResourceAvailable("Concrete", 100));
    CHECK(resourceManager->consumeResource("Concrete", 100));
    CHECK(resourceManager->isResourceAvailable("Steel", 50));
    CHECK_FALSE(resourceManager->consumeResource("Steel", 500));
}
