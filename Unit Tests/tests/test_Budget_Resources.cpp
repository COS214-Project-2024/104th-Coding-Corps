// test_Budget_Resources.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../Budget.h"
#include "../ConcreteFactory.h"
#include "../ResourceManager.h"
#include "../SteelFactory.h"

// Budget Singleton and Financial Transactions Test
TEST_CASE("Budget Singleton and Financial Transactions") {
    auto budget = Budget::getInstance();

    budget->addRevenue(10000);
    CHECK(budget->getBalance() == 10000);

    CHECK(budget->deductExpense(2500));
    CHECK(budget->getBalance() == 7500);

    CHECK_FALSE(budget->deductExpense(8000));
    CHECK(budget->getBalance() == 7500); // Balance should remain the same after failed deduction
}

// ConcreteFactory Test
TEST_CASE("ConcreteFactory creates Concrete resource") {
    ConcreteFactory concreteFactory;
    auto concrete = concreteFactory.createResource(500);

    CHECK(concrete->getName() == "Concrete");
    CHECK(concrete->getQuantity() == 500);
}

// ResourceManager Singleton and Resource Handling Test
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
