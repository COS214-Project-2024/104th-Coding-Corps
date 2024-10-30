// test/Budget_test.cpp
#include "doctest.h"
#include "Budget.h"

TEST_CASE("Budget Singleton and Financial Transactions") {
    auto budget = Budget::getInstance();

    budget->addRevenue(10000);
    CHECK(budget->getBalance() == 10000);

    CHECK(budget->deductExpense(2500));
    CHECK(budget->getBalance() == 7500);

    CHECK_FALSE(budget->deductExpense(8000));
    CHECK(budget->getBalance() == 7500); // Balance should remain the same after failed deduction
}
