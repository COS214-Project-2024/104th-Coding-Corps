#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Citizen.h"
#include "CityContext.h"
#include "Transport.h"
#include <memory>

TEST_SUITE("Citizen Class Tests") {
    std::shared_ptr<CityContext> cityContext = std::make_shared<CityContext>();
    std::shared_ptr<Transport> transportContext = std::make_shared<Transport>();

    TEST_CASE("Constructor Test") {
        Citizen citizen(cityContext, transportContext);

        CHECK(citizen.getSatisfaction() == 50);
        CHECK(citizen.getESoL() == 50);
        CHECK(citizen.getASoL() == 50);
        CHECK(citizen.getX() == 0);
        CHECK(citizen.getY() == 0);
        CHECK(citizen.getEducationLevel() == 0);
    }

    TEST_CASE("Employment Status") {
        Citizen citizen(cityContext, transportContext);
        //CHECK(citizen.getEmployment() == true || citizen.getEmployment() == false); //Compiler does not like this

        bool initialEmployment = citizen.getEmployment();
        citizen.updateEmployment();
        CHECK(citizen.getEmployment() == !initialEmployment);
    }

    TEST_CASE("Income Update") {
        Citizen citizen(cityContext, transportContext);

        double initialIncome = citizen.getCurrentIncome();
        citizen.updateCurrentIncome(1000);
        CHECK(citizen.getCurrentIncome() == initialIncome + 1000);
    }

    TEST_CASE("Satisfaction Update") {
        Citizen citizen(cityContext, transportContext);

        int initialSatisfaction = citizen.getSatisfaction();
        citizen.updateSatisfaction(10);
        CHECK(citizen.getSatisfaction() == initialSatisfaction + 10);

        citizen.updateSatisfaction(-20);
        CHECK(citizen.getSatisfaction() == std::max(0, initialSatisfaction - 10));
    }

    TEST_CASE("Class Promotion and Demotion") {
        Citizen citizen(cityContext, transportContext);
        
        citizen.updateCurrentIncome(400000);
        CHECK(citizen.getCurrentIncome() >= 300000);
        CHECK(citizen.getSatisfaction() >= 50);

        citizen.updateCurrentIncome(-350000);
        CHECK(citizen.getCurrentIncome() < 300000);
    }

    // TEST_CASE("Tax Calculation") {
    //     Citizen citizen(cityContext, transportContext);
    //     citizen.updateCurrentIncome(100000);
    //     CHECK(citizen.calculateTax() == Approx(100000 * 0.1).epsilon(0.01));

    //     citizen.updateCurrentIncome(400000);
    //     CHECK(citizen.calculateTax() == Approx(400000 * 0.22).epsilon(0.01));

    //     citizen.updateCurrentIncome(1200000);
    //     CHECK(citizen.calculateTax() == Approx(1200000 * 0.35).epsilon(0.01));
    // }

    TEST_CASE("Go To Work Test") {
        Citizen citizen(cityContext, transportContext);
        int initialIncome = citizen.getCurrentIncome();
        
        citizen.goToWork();
        CHECK(citizen.getCurrentIncome() > initialIncome);
    }

    TEST_CASE("Shopping Test") {
        Citizen citizen(cityContext, transportContext);
        int initialSatisfaction = citizen.getSatisfaction();

        citizen.goToShops();
        CHECK(citizen.getSatisfaction() != initialSatisfaction);
    }

    TEST_CASE("Education and Job Update") {
        Citizen citizen(cityContext, transportContext);

        int initialEducationLevel = citizen.getEducationLevel();
        citizen.getSchooled();
        CHECK(citizen.getEducationLevel() == initialEducationLevel + 1);
    }

    TEST_CASE("Health Care Test") {
        Citizen citizen(cityContext, transportContext);
        int initialSatisfaction = citizen.getSatisfaction();

        citizen.getHealed();
        CHECK(citizen.getSatisfaction() != initialSatisfaction);
    }
}
