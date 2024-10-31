#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <memory>
#include "../ServiceBuildingFactory.h"
#include "../ResidentialBuildingFactory.h"
#include "../CommercialBuildingFactory.h"
#include "../IndustrialBuildingFactory.h"
#include "../School.h"
#include "../House.h"
#include "../Shop.h"
#include "../Factory.h"
#include "../University.h"
#include "../Hospital.h"

TEST_CASE("ServiceBuildingFactory creates a School Building") {
    ServiceBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createSchool(0, 0, "District A", 56, 70, 3);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "School");
    CHECK(building->getCost() > 0);
}

TEST_CASE("ServiceBuildingFactory creates a University Building") {
    ServiceBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createUniversity(0, 0, "District A", 56, 70, 3);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "University");
    CHECK(building->getCost() > 0);
}

TEST_CASE("ServiceBuildingFactory creates a Hospital Building") {
    ServiceBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createHospital(0, 0, "District A", 56, 70);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Hospital");
    CHECK(building->getCost() > 0);
}

TEST_CASE("ResidentialBuildingFactory creates a House Building") {
    ResidentialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createHouse(2, true, 3, 1, true, "District B", 60);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "House");
    CHECK(building->getCost() > 0);
}

TEST_CASE("ResidentialBuildingFactory creates a Flat Building") {
    ResidentialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createFlat(10, 20, 5, false, "District B", 60);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Flat");
    CHECK(building->getCost() > 0);
}

TEST_CASE("ResidentialBuildingFactory creates an Estate Building") {
    ResidentialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createEstate(450, true, 150, 10, true, 20, "District B", 60);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Estate");
    CHECK(building->getCost() > 0);
}

TEST_CASE("CommercialBuildingFactory creates a Shop Building") {
    CommercialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createShop(100, "Bakery", 10, 20, "District C", 56);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Shop");
    CHECK(building->getCost() > 0);
}

TEST_CASE("CommercialBuildingFactory creates a Mall Building") {
    CommercialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createMall(50, "Many", 21, 10, 20, "District C", 56);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Mall");
    CHECK(building->getCost() > 0);
}

TEST_CASE("CommercialBuildingFactory creates an Office Building") {
    CommercialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createOffice(50, "Law", "District C", 56, 10, 20);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Office");
    CHECK(building->getCost() > 0);
}

TEST_CASE("IndustrialBuildingFactory creates a Factory Building") {
    IndustrialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createFactory(0, 0, "District D", 75, 150, "Steel", 10000.00);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Factory");
    CHECK(building->getCost() > 0);
}

TEST_CASE("IndustrialBuildingFactory creates a Plant Building") {
    IndustrialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createPlant(0, 0, "District D", 75, 20000.00, 1500);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Plant");
    CHECK(building->getCost() > 0);
}

TEST_CASE("IndustrialBuildingFactory creates a Warehouse Building") {
    IndustrialBuildingFactory factory;
    std::unique_ptr<BuildingComponent> building = factory.createWarehouse(0, 0, "District D", 75, 20000, 1500);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Warehouse");
    CHECK(building->getCost() > 0);
}
