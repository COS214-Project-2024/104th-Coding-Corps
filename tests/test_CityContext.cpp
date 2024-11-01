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
        citizen = Citizen::createCitizen(cityContext, transportContext, government);
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
        auto citizen2 = Citizen::createCitizen(cityContext, transportContext, government);

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

        SUBCASE("Calculate Average Satisfaction") {
            citizen->updateSatisfaction(80);
            citizen2->updateSatisfaction(60);
            cityContext->attach(citizen);
            cityContext->attach(citizen2);
            CHECK(cityContext->calculateAverageSatisfaction() == 70);
        }
    }

    // Building Management Tests
    TEST_CASE("CityContext Building Management") {
        auto cityContext = CityContext::getInstance();
        auto flat1 = std::make_shared<Flat>(0, 0, "A", 75, 10, 20, 5, true);
        auto flat2 = std::make_shared<Flat>(1, 1, "B", 85, 8, 15, 3, false);

        SUBCASE("Add Buildings") {
            cityContext->addBuilding(flat1);
            cityContext->addBuilding(flat2);
            CHECK(cityContext->calculateTotalBuildings() == 2);
        }

        SUBCASE("Remove Buildings") {
            cityContext->addBuilding(flat1);
            cityContext->addBuilding(flat2);
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
        auto flat = std::make_shared<Flat>(0, 0, "Downtown", 80, 10, 20, 5, true);

        citizen->updateSatisfaction(85);
        citizen->updateCurrentIncome(3000);
        citizen->increaseEducation();
        cityContext->attach(citizen);

        cityContext->addBuilding(flat);

        SUBCASE("Calculate Monthly Expenditure") {
            CHECK(cityContext->calculateMonthlyExpenditure() == 2100);  // Assuming 70% of income
        }

        SUBCASE("Calculate Total Energy and Water Consumption") {
            CHECK(cityContext->calculateTotalEnergyConsumption() == flat->getEnergyConsumption());
            CHECK(cityContext->calculateTotalWaterConsumption() == flat->getWaterConsumption());
        }

        SUBCASE("Calculate Averages and Summary") {
            cityContext->calculateAverages();
            CHECK(cityContext->calculateAverageSatisfaction() == 85);
            CHECK(cityContext->calculateAverageIncome() == 3000);
            CHECK(cityContext->calculateAverageEducationLevel() == 1); // Since one citizen has level 1
        }
    }

    // Memento (SavePoint) Tests
    TEST_CASE_FIXTURE(CitizenFixture, "CityContext Save and Restore") {
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
}
