#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../Citizen.h"
#include "../CityContext.h"
#include "../Transport.h"
#include "../Government.h"
#include <memory>

TEST_SUITE("Citizen Class Tests") {
    // Adjusted to use getInstance() if available
    std::shared_ptr<CityContext> cityContext = CityContext::getInstance(); // Use getInstance()
    std::shared_ptr<Transport> transportContext = std::make_shared<Transport>();
    std::shared_ptr<Government> governmentContext = Government::getInstance(); // Use getInstance()

    TEST_CASE("Constructor Test") {
        auto citizen = std::make_shared<Citizen>(cityContext, transportContext, governmentContext);

        CHECK(citizen->getSatisfaction() == 50);
        CHECK(citizen->getESoL() == 50);
        CHECK(citizen->getASoL() == 50);
        CHECK(citizen->getX() == 0);
        CHECK(citizen->getY() == 0);
        CHECK(citizen->getEducationLevel() == 0);
    }

    TEST_CASE("Employment Status") {
        Citizen citizen(cityContext, transportContext, governmentContext);

        bool initialEmployment = citizen.getEmployment();
        citizen.updateEmployment();
        CHECK(citizen.getEmployment() == !initialEmployment);
    }

    TEST_CASE("Income Update") {
        Citizen citizen(cityContext, transportContext, governmentContext);

        double initialIncome = citizen.getCurrentIncome();
        citizen.updateCurrentIncome(1000);
        CHECK(citizen.getCurrentIncome() == initialIncome + 1000);
    }

    TEST_CASE("Satisfaction Update") {
        Citizen citizen(cityContext, transportContext, governmentContext);

        int initialSatisfaction = citizen.getSatisfaction();
        citizen.updateSatisfaction(10);
        CHECK(citizen.getSatisfaction() == initialSatisfaction + 10);

        citizen.updateSatisfaction(-20);
        CHECK(citizen.getSatisfaction() == std::max(0, initialSatisfaction - 10));
    }

    TEST_CASE("Class Promotion and Demotion") {
        Citizen citizen(cityContext, transportContext, governmentContext);

        citizen.updateCurrentIncome(400000);
        CHECK(citizen.getCurrentIncome() >= 300000);
        CHECK(citizen.getSatisfaction() >= 50);

        citizen.updateCurrentIncome(-350000);
        CHECK(citizen.getCurrentIncome() < 300000);
    }

    TEST_CASE("Go To Work Test") {
        Citizen citizen(cityContext, transportContext, governmentContext);
        int initialIncome = citizen.getCurrentIncome();

        citizen.goToWork();
        CHECK(citizen.getCurrentIncome() > initialIncome);
    }

    TEST_CASE("Shopping Test") {
        Citizen citizen(cityContext, transportContext, governmentContext);
        int initialSatisfaction = citizen.getSatisfaction();

        citizen.goToShops();
        CHECK(citizen.getSatisfaction() != initialSatisfaction);
    }

    TEST_CASE("Education and Job Update") {
        Citizen citizen(cityContext, transportContext, governmentContext);

        int initialEducationLevel = citizen.getEducationLevel();
        citizen.getSchooled();
        CHECK(citizen.getEducationLevel() == initialEducationLevel + 1);
    }

    TEST_CASE("Health Care Test") {
        Citizen citizen(cityContext, transportContext, governmentContext);
        int initialSatisfaction = citizen.getSatisfaction();

        citizen.getHealed();
        CHECK(citizen.getSatisfaction() != initialSatisfaction);
    }
}
