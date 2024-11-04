#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../CityContext.h"
#include "../Flat.h"
#include "../WaterSupply.h"
#include "../Transport.h"
#include "../Government.h"
#include <memory>

// Fixture to set up common objects for CityContext and Citizen tests
struct CitizenFixture {
    std::shared_ptr<CityContext> cityContext;
    std::shared_ptr<Transport> transportContext;
    std::shared_ptr<Government> government;
    std::shared_ptr<Citizen> citizen;

    CitizenFixture() {
        cityContext = CityContext::getInstance();
        government = Government::getInstance();
        transportContext = std::make_shared<Transport>();
        citizen = std::make_shared<Citizen>(cityContext, transportContext, government);
        cityContext->attach(citizen);
        citizen->initialize();
    }
};

TEST_SUITE("CityContext Tests") {

    // Singleton Test
    TEST_CASE("CityContext Singleton Test") {
        auto instance1 = CityContext::getInstance();
        auto instance2 = CityContext::getInstance();
        CHECK(instance1 == instance2);  // Ensures only one instance exists
    }

    // Citizen Management Tests
    TEST_CASE_FIXTURE(CitizenFixture, "CityContext Citizen Management") {
        std::shared_ptr<Citizen> citizen2 = std::make_shared<Citizen>(cityContext, transportContext, government);
        cityContext->attach(citizen2);
        citizen2->initialize();

        cityContext->reset();
        SUBCASE("Attach Citizens") {
            cityContext->attach(citizen);
            cityContext->attach(citizen2);
            CHECK(cityContext->calculateTotalPop() == 2);
        }

        SUBCASE("Detach Citizens") {
            cityContext->attach(citizen);
            cityContext->attach(citizen2);
            cityContext->detach(citizen);
            cityContext->detach(citizen2);
            CHECK(cityContext->calculateTotalPop() == 0);
        }

    }

    // Building Management Tests
    TEST_CASE("CityContext Building Management") {
        auto cityContext = CityContext::getInstance();
        auto flat1 = std::make_shared<Flat>(0, 0, "A", 75, 10, 20, 5, true);
        auto flat2 = std::make_shared<Flat>(1, 1, "B", 85, 8, 15, 3, false);
        cityContext->reset();

        SUBCASE("Add Buildings") {
            cityContext->addBuilding(flat1);
            cityContext->addBuilding(flat2);
            CHECK(cityContext->calculateTotalBuildings() == 2);
        }

        SUBCASE("Remove Buildings") {
            // cityContext->addBuilding(flat1);
            // cityContext->addBuilding(flat2);
            cityContext->removeBuilding(flat1);
            cityContext->removeBuilding(flat2);
            CHECK(cityContext->calculateTotalBuildings() == 0);
        }

        SUBCASE("Calculate Average Building Quality") {
            cityContext->addBuilding(flat1);
            cityContext->addBuilding(flat2);
            CHECK(cityContext->calculateAverageBuildingQuality() == 80);
        }

        SUBCASE("Calculate Total Energy and Water Consumption") {
            cityContext->addBuilding(flat1);
            cityContext->addBuilding(flat2);
            double expectedEnergy = flat1->getEnergyConsumption() + flat2->getEnergyConsumption();
            double expectedWater = flat1->getWaterConsumption() + flat2->getWaterConsumption();
            CHECK(cityContext->calculateTotalEnergyConsumption() == doctest::Approx(expectedEnergy));
            CHECK(cityContext->calculateTotalWaterConsumption() == doctest::Approx(expectedWater));
        }
    }

    // Utilities Management Tests
    TEST_CASE("CityContext Utility Management") {
        auto cityContext = CityContext::getInstance();
        auto waterSupply1 = std::make_shared<WaterSupply>();
        auto waterSupply2 = std::make_shared<WaterSupply>();
        cityContext->reset();

        SUBCASE("Add Utilities") {
            cityContext->addUtility(waterSupply1);
            cityContext->addUtility(waterSupply2);
            CHECK(cityContext->countTotalUtilities() == 2);
        }

        SUBCASE("Remove Utilities") {
            cityContext->addUtility(waterSupply1);
            cityContext->addUtility(waterSupply2);
            cityContext->removeUtility(waterSupply1);
            cityContext->removeUtility(waterSupply2);
            CHECK(cityContext->countTotalUtilities() == 0);
        }

        SUBCASE("Calculate Total Water Production") {
            waterSupply1->activateUtility();
            waterSupply2->activateUtility();
            cityContext->addUtility(waterSupply1);
            cityContext->addUtility(waterSupply2);
            double expectedWaterProduction = waterSupply1->getConsumptionRate() + waterSupply2->getConsumptionRate();
            CHECK(cityContext->calculateTotalWaterProduction() == doctest::Approx(expectedWaterProduction));
        }
    }

    // Averages and Summaries Tests
    TEST_CASE_FIXTURE(CitizenFixture, "CityContext Averages and Summaries") {
        cityContext->reset();
        auto flat = std::make_shared<Flat>(0, 0, "Downtown", 80, 10, 20, 5, true);

        citizen->updateSatisfaction(85);
        citizen->updateCurrentIncome(3000);
        citizen->increaseEducation();
        cityContext->attach(citizen);
        int expectedIncome = citizen->getCurrentIncome();
        int expectedExpenditure = expectedIncome*0.7;

        cityContext->addBuilding(flat);

        SUBCASE("Calculate Monthly Expenditure") {
            CHECK(cityContext->calculateMonthlyExpenditure() == doctest::Approx(expectedExpenditure));  // Assuming 70% of income
        }

        SUBCASE("Calculate Total Energy and Water Consumption") {
            CHECK(cityContext->calculateTotalEnergyConsumption() == flat->getEnergyConsumption());
            CHECK(cityContext->calculateTotalWaterConsumption() == flat->getWaterConsumption());
        }

        SUBCASE("Calculate Averages and Summary") {
            cityContext->calculateAverages();
            CHECK(cityContext->calculateAverageSatisfaction() == 100);
            CHECK(cityContext->calculateAverageIncome() == expectedIncome);
        }
    }

    // Memento (SavePoint) Tests
    TEST_CASE_FIXTURE(CitizenFixture, "CityContext Save and Restore") {
        cityContext->reset();
        auto flat = std::make_shared<Flat>(0, 0, "Downtown", 80, 10, 20, 5, true);
        auto waterSupply = std::make_shared<WaterSupply>();

        cityContext->attach(citizen);
        cityContext->addBuilding(flat);
        cityContext->addUtility(waterSupply);

        auto savePoint = cityContext->saveGame();
        citizen->updateSatisfaction(50);  // Changing some values post-save
        cityContext->detach(citizen);
        cityContext->removeBuilding(flat);
        cityContext->removeUtility(waterSupply);

        SUBCASE("Restore State") {
            cityContext->setSavePoint(savePoint);
            CHECK(cityContext->calculateTotalPop() == 1); // Citizen re-attached
            CHECK(cityContext->calculateTotalBuildings() == 1); // Building re-attached
            CHECK(cityContext->countTotalUtilities() == 1); // Utility re-attached
        }
    }

        //Policy Enforcement Tests
    TEST_CASE("CityContext Policy Enforcement") {
        auto cityContext = CityContext::getInstance();
        cityContext->enforcePolicy("tax rate", "high");  // Assuming "high" is a valid value for "tax rate"
        
        SUBCASE("Valid Policy Update") {
            // Assuming "tax rate" is a policy key in `CityContext` with allowed values {"low", "medium", "high"}
            cityContext->enforcePolicy("tax rate", "standard");
            CHECK(cityContext->getPolicyValue("tax rate") == "standard");

            cityContext->enforcePolicy("tax rate", "low");
            CHECK(cityContext->getPolicyValue("tax rate") == "low");
        }

        SUBCASE("Invalid Policy Update") {
            // Trying to set an invalid policy value, which should not change the policy
            cityContext->enforcePolicy("tax rate", "invalid_value");
            CHECK(cityContext->getPolicyValue("tax rate") != "invalid_value");  // Check it didn't update
        }

        SUBCASE("Nonexistent Policy Key") {
            // Attempting to update a policy that doesn’t exist
            cityContext->enforcePolicy("unknown_policy", "some_value");
            // There should be no policy change, so we expect no crash or update
        }
    }
}


