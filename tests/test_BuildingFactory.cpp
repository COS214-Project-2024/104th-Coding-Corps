#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
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
    BuildingComponent* building = factory.createSchool(3, 56, 70);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "School");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("ServiceBuildingFactory creates a University Building") {
    ServiceBuildingFactory factory;
    BuildingComponent* building = factory.createUniversity(3, 56, 70);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "University");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("ServiceBuildingFactory creates a Hospital Building") {
    ServiceBuildingFactory factory;
    BuildingComponent* building = factory.createHospital(56, 70);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Hospital");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("ResidentialBuildingFactory creates a House Building") {
    ResidentialBuildingFactory factory;
    BuildingComponent* building = factory.createHouse(2, true, 3, 1, true);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "House");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("ResidentialBuildingFactory creates a Flat Building") {
    ResidentialBuildingFactory factory;
    BuildingComponent* building = factory.createFlat(10, 20, 5, false);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Flat");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("ResidentialBuildingFactory creates an Estate Building") {
    ResidentialBuildingFactory factory;
    BuildingComponent* building = factory.createEstate(450, true, 150, 10, true, 20);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Estate");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("CommercialBuildingFactory creates a Shop Building") {
    CommercialBuildingFactory factory;
    BuildingComponent* building = factory.createShop(100, "Bakery");

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Shop");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("CommercialBuildingFactory creates a Shop Building") {
    CommercialBuildingFactory factory;
    BuildingComponent* building = factory.createShop(100, "Bakery");

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Shop");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("CommercialBuildingFactory creates a Mall Building") {
    CommercialBuildingFactory factory;
    BuildingComponent* building = factory.createMall(50, "Many", 15);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Mall");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("CommercialBuildingFactory creates an Office Building") {
    CommercialBuildingFactory factory;
    BuildingComponent* building = factory.createOffice(50, "Law");

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Office");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("IndustrialBuildingFactory creates a Factory Building") {
    IndustrialBuildingFactory factory;
    BuildingComponent* building = factory.createFactory(150, "Steel", 10000.00);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Factory");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("IndustrialBuildingFactory creates a Factory Building") {
    IndustrialBuildingFactory factory;
    BuildingComponent* building = factory.createPlant(1500, 20000.00);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Plant");
    CHECK(building->getCost() > 0);

    delete building;
}

TEST_CASE("IndustrialBuildingFactory creates a Warehouse Building") {
    IndustrialBuildingFactory factory;
    BuildingComponent* building = factory.createWarehouse(1500, 20000.00);

    REQUIRE(building != nullptr);
    CHECK(building->getBuildingType() == "Warehouse");
    CHECK(building->getCost() > 0);

    delete building;
}
