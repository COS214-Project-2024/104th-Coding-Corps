#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../Family.h"
#include "../CityContext.h"
#include "../Government.h"
#include "../Citizen.h"
#include <memory>

TEST_SUITE("Family Class Tests") {
    std::shared_ptr<CityContext> cityContext = CityContext::getInstance();
    std::shared_ptr<Government> government = Government::getInstance();

    TEST_CASE("Family Initialization") {
        Family family(cityContext, government, "Downtown");
        CHECK(family.getSatisfaction() == 0);
        CHECK(family.getESoL() == 0);
        CHECK(family.getASoL() == 0);
        CHECK(family.getCurrentIncome() == 0);
        CHECK(family.getMonthlyExpenditure() == 0);
    }

    TEST_CASE("Adding and Removing Citizens") {
        Family family(cityContext, government, "Downtown");
        auto citizen1 = Citizen::createCitizen(cityContext, nullptr, government);
        auto citizen2 = Citizen::createCitizen(cityContext, nullptr, government);

        family.add(citizen1);
        family.add(citizen2);

        CHECK(family.getCurrentIncome() > 0);  // Assuming citizens have positive income
        CHECK(family.getSatisfaction() >= 0);  // Satisfaction should be initialized to a valid range

        family.remove(citizen1);
        CHECK(family.getCurrentIncome() == citizen2->getCurrentIncome());  // Income should match remaining citizen's income
    }


    TEST_CASE("Moving District") {
        Family family(cityContext, government, "Downtown");
        family.moveDistrict("Uptown");
        // Assuming we have access to verify the district change in Family
        CHECK(family.getDistrict() == "Uptown");
    }

    TEST_CASE("Calculating Monthly Expenditure") {
        Family family(cityContext, government, "Downtown");
        auto citizen = Citizen::createCitizen(cityContext, nullptr, government);
        family.add(citizen);
        
        CHECK(family.getMonthlyExpenditure() == doctest::Approx(citizen->getCurrentIncome() * 0.7));
    }

    TEST_CASE("Tax Calculation and Payment") {
        Family family(cityContext, government, "Downtown");
        auto citizen = Citizen::createCitizen(cityContext, nullptr, government);
        family.add(citizen);

        double taxAmount = family.calculateTax();
        CHECK(taxAmount == doctest::Approx(citizen->calculateTax()));

        // Test if tax amount is added to government budget
        double initialBudget = government->getBalance();
        family.payTax(taxAmount);
        CHECK(government->getBalance() == doctest::Approx(initialBudget + taxAmount));
    }
    
    TEST_CASE("Resource Update") {
        Family family(cityContext, government, "Downtown");
        auto citizen = Citizen::createCitizen(cityContext, nullptr, government);
        family.add(citizen);

        family.update("water", 100);
        // Assuming update behavior can be verified in some way; otherwise, this test checks for any runtime issues.
    }

    TEST_CASE("Sending Family Members to Work, School, and Shops") {
        Family family(cityContext, government, "Downtown");
        auto citizen = Citizen::createCitizen(cityContext, nullptr, government);
        family.add(citizen);

        family.goToWork();
        family.goToShops();
        family.getSchooled();
        family.getEducated();
        family.getHealed();
        // Since these methods don’t return values, this test mainly ensures no runtime issues occur.
    }
}
