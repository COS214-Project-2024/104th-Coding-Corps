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
    School school(10, 10, "District A",  56, 40, 10);

    CHECK(school.getBuildingType() == "School");
    CHECK(school.getOccupancy() == 1500);
    CHECK(school.getCost() == 3000000.0);
    CHECK(school.getMaintenanceCost() == 0.03 * 3000000.0);
    CHECK(school.getEnergyConsumption() == 40 * 200.0);
    CHECK(school.getWaterConsumption() == 40 * 80.0);

    school.demolish();
    CHECK(school.getHighestQualification() == 0);
}

TEST_CASE("University tests") {
    University university(10, 10, "District A", 56, 60, 10);

    CHECK(university.getBuildingType() == "University");
    CHECK(university.getOccupancy() == 20000);
    CHECK(university.getCost() == 10000000.0);
    CHECK(university.getMaintenanceCost() == 0.04 * 10000000.0);
    CHECK(university.getEnergyConsumption() == 60 * 300.0);
    CHECK(university.getWaterConsumption() == 60 * 100.0);

    university.demolish();
    CHECK(university.getHighestQualification() == 0);
}

TEST_CASE("Hospital tests") {
    Hospital hospital(10, 10, "District A", 56, 60);

    CHECK(hospital.getBuildingType() == "Hospital");
    CHECK(hospital.getOccupancy() == 5000);
    CHECK(hospital.getCost() == 7000000.0);
    CHECK(hospital.getMaintenanceCost() == 0.05 * 7000000.0);
    CHECK(hospital.getEnergyConsumption() == 60 * 400.0);
    CHECK(hospital.getWaterConsumption() == 60 * 150.0);

    hospital.demolish();
}

// --- Residential Buildings ---

TEST_CASE("House tests") {
    House house(10, 10, "District A", 56, 5, true, 6, 10, true);

    CHECK(house.getBuildingType() == "House");
    CHECK(house.getGarageSize() == 5);
    CHECK(house.hasSwimmingPool() == true);
    CHECK(house.getCost() > 0);
    CHECK(house.getOccupancy() == 10);

    house.demolish();
    CHECK(house.getGarageSize() == 0);
}

TEST_CASE("Flat tests") {
    Flat apartment(10, 10, "District A", 56, 50, 300, 6, false);
    CHECK(apartment.getBuildingType() == "Flat");
    CHECK(apartment.getNumUnits() == 50);
    CHECK(apartment.getOccupancy() == 10 * 5);
    CHECK(apartment.getCost() == 1595000.00);
    CHECK(apartment.getMaintenanceCost() == 0.02 * 1595000.00);

    apartment.demolish();
    CHECK(apartment.getNumUnits() == 0);
}

// --- Commercial Buildings ---

TEST_CASE("Shop tests") {
    Shop shop(10, "Fruit", 10, 10, "District A", 30);

    CHECK(shop.getBuildingType() == "Shop");
    CHECK(shop.getCost() == 2000000.0);
    CHECK(shop.getMaintenanceCost() > 0);
    CHECK(shop.getEnergyConsumption() > 0);
    CHECK(shop.getWaterConsumption() > 0);
}

TEST_CASE("Mall tests") {
    Mall mall(50, "Variety", 50, 5, 5, "District A", 56);

    CHECK(mall.getBuildingType() == "Mall");
    CHECK(mall.getNumShops() == 50);
    CHECK(mall.getOccupancy() == 100);
    CHECK(mall.getCost() == 50 * 5000000.0);
    CHECK(mall.getMaintenanceCost() == 0.03 * 5000000.0 * 50);

    mall.demolish();
    CHECK(mall.getNumShops() == 0);
}

// --- Industrial Buildings ---

TEST_CASE("Factory tests") {
    factory factory(10, 10, "District A", 56, 20, "Steel", 50);

    CHECK(factory.getBuildingType() == "Factory");
    CHECK(factory.getOccupancy() == 150);
    CHECK(factory.getCost() == 150000000.0);
    CHECK(factory.getMaintenanceCost() == 0.05 * 150000000.0);
    CHECK(factory.getEnergyConsumption() == 150 * 500.0);
    CHECK(factory.getWaterConsumption() == 150 * 2000.0);

    factory.demolish();
}

TEST_CASE("Warehouse tests") {
    Warehouse warehouse(10, 10, "District A", 56, 500, 40);

    CHECK(warehouse.getBuildingType() == "Warehouse");
    CHECK(warehouse.getStorageCapacity() == 500);
    CHECK(warehouse.getCost() == 90000000.0);
    CHECK(warehouse.getMaintenanceCost() == 0.03 * 90000000.0);
    CHECK(warehouse.getEnergyConsumption() > 0);
    CHECK(warehouse.getWaterConsumption() > 0);

    warehouse.demolish();
    CHECK(warehouse.getStorageCapacity() == 0);
}
