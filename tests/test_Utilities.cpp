#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../WaterSupply.h"
#include "../sewageManagement.h"
#include "../wasteManagement.h"
#include "../PowerPlant.h"
#include <doctest/doctest.h>

TEST_CASE("WaterSupply tests") {
    WaterSupply waterSupply;

    CHECK(waterSupply.getUtilityType() == "Water Supply");
    CHECK(waterSupply.getConsumptionRate() == 1000.0);
    CHECK(waterSupply.getCost() == 50000.0);

    waterSupply.activateUtility();

    waterSupply.deactivateUtility();
}

TEST_CASE("SewageManagement tests") {
    SewageManagement sewageManagement;

    CHECK(sewageManagement.getUtilityType() == "Sewage Management");
    CHECK(sewageManagement.getConsumptionRate() == 15.0);
    CHECK(sewageManagement.getCost() == 120000.0);

    sewageManagement.activateUtility();

    sewageManagement.deactivateUtility();
}

TEST_CASE("WasteManagement tests") {
    WasteManagement wasteManagement;

    CHECK(wasteManagement.getUtilityType() == "Waste Management");
    CHECK(wasteManagement.getConsumptionRate() == 20.0);
    CHECK(wasteManagement.getCost() == 100000.0);

    wasteManagement.activateUtility();

    wasteManagement.deactivateUtility();
}

/*TEST_CASE("PowerPlant tests") {
    PowerPlant powerPlant;

    CHECK(powerPlant.getUtilityType() == "Power Plant");
    CHECK(powerPlant.getConsumptionRate() == 1500.0);
    CHECK(powerPlant.getCost() == 200000.0);

    powerPlant.activateUtility();

    powerPlant.deactivateUtility();
}
*/