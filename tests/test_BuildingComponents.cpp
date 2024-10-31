#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

// Service Building Includes
#include "../School.h"
#include "../University.h"
#include "../Hospital.h"

// Residential Building Includes
#include "../House.h"
#include "../Flat.h"

// Commercial Building Includes
#include "../Shop.h"
#include "../mall.h"

// Industrial Building Includes
#include "../Factory.h"
#include "../warehouse.h"

// --- Service Buildings ---

TEST_CASE("School tests") {
    School school(5, 100, 12);

    CHECK(school.getBuildingType() == "School");
    CHECK(school.getOccupancy() == 1500);
    CHECK(school.getCost() == 3000000.0);
    CHECK(school.getMaintenanceCost() == 0.03 * 3000000.0);
    CHECK(school.getEnergyConsumption() == 100 * 200.0);
    CHECK(school.getWaterConsumption() == 100 * 80.0);

    school.demolish();
    CHECK(school.getHighestQualification() == 0);
}

TEST_CASE("University tests") {
    University university(5, 200, 15);

    CHECK(university.getBuildingType() == "University");
    CHECK(university.getOccupancy() == 20000);
    CHECK(university.getCost() == 10000000.0);
    CHECK(university.getMaintenanceCost() == 0.04 * 10000000.0);
    CHECK(university.getEnergyConsumption() == 200 * 300.0);
    CHECK(university.getWaterConsumption() == 200 * 100.0);

    university.demolish();
    CHECK(university.getHighestQualification() == 0);
}

TEST_CASE("Hospital tests") {
    Hospital hospital(56, 70);

    CHECK(hospital.getBuildingType() == "Hospital");
    CHECK(hospital.getOccupancy() == 5000);
    CHECK(hospital.getCost() == 7000000.0);
    CHECK(hospital.getMaintenanceCost() == 0.05 * 7000000.0);
    CHECK(hospital.getEnergyConsumption() == 70 * 400.0);
    CHECK(hospital.getWaterConsumption() == 70 * 150.0);

    hospital.demolish();
}

// --- Residential Buildings ---

TEST_CASE("House tests") {
    House house(2, true, 5, 2, true);

    CHECK(house.getBuildingType() == "House");
    CHECK(house.getGarageSize() == 2);
    CHECK(house.hasSwimmingPool() == true);
    CHECK(house.getCost() > 0);
    CHECK(house.getOccupancy() == 5);

    house.demolish();
    CHECK(house.getGarageSize() == 0);
}

TEST_CASE("Flat tests") {
    Flat apartment(10, 20, 5, false);
    CHECK(apartment.getBuildingType() == "Flat");
    CHECK(apartment.getNumUnits() == 20);
    CHECK(apartment.getOccupancy() == 10 * 20);
    CHECK(apartment.getCost() == 5000000.0);
    CHECK(apartment.getMaintenanceCost() == 0.02 * 5000000.0);

    apartment.demolish();
    CHECK(apartment.getNumUnits() == 0);
}

// --- Commercial Buildings ---

TEST_CASE("Shop tests") {
    Shop shop(100, "Bakery");

    CHECK(shop.getBuildingType() == "Shop");
    CHECK(shop.getCost() == 2000000.0);
    CHECK(shop.getMaintenanceCost() > 0);
    CHECK(shop.getEnergyConsumption() > 0);
    CHECK(shop.getWaterConsumption() > 0);
}

TEST_CASE("Mall tests") {
    Mall mall(50, "Many", 15);

    CHECK(mall.getBuildingType() == "Mall");
    CHECK(mall.getNumShops() == 50);
    CHECK(mall.getOccupancy() == 5000);
    CHECK(mall.getCost() == 25000000.0);
    CHECK(mall.getMaintenanceCost() == 0.04 * 25000000.0);

    mall.demolish();
    CHECK(mall.getNumShops() == 0);
}

// --- Industrial Buildings ---

TEST_CASE("Factory tests") {
    Factory factory(100, "Manufacturing", 20);

    CHECK(factory.getBuildingType() == "Factory");
    CHECK(factory.getOccupancy() == 100);
    CHECK(factory.getCost() == 150000000.0);
    CHECK(factory.getMaintenanceCost() == 0.05 * 150000000.0);
    CHECK(factory.getEnergyConsumption() == 100 * 500.0);
    CHECK(factory.getWaterConsumption() == 100 * 2000.0);

    factory.demolish();
}

TEST_CASE("Warehouse tests") {
    Warehouse warehouse(200, 10000);

    CHECK(warehouse.getBuildingType() == "Warehouse");
    CHECK(warehouse.getStorageCapacity() == 200);
    CHECK(warehouse.getCost() == 90000000.0);
    CHECK(warehouse.getMaintenanceCost() == 0.03 * 90000000.0);
    CHECK(warehouse.getEnergyConsumption() > 0);
    CHECK(warehouse.getWaterConsumption() > 0);

    warehouse.demolish();
    CHECK(warehouse.getStorageCapacity() == 0);
}
