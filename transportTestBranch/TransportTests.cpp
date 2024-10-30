#include "Transport.h"
#include "BuildingComponent.h"
#include "IndustrialBuildings.h" 
#include "Factory.h"
#include "Flat.h"
#include "House.h"
#include "Office.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <memory>

TEST_CASE("Transport Class Tests") {
    Transport transport;

    auto factory = std::make_shared<Factory>(100, "cotton", 300);
    auto flat = std::make_shared<Flat>(100, 150, 5, false); 
    auto house = std::make_shared<House>(2, true, 4, 2, true);
    auto office = std::make_shared<Office>(250, "technology"); 

    CHECK(transport.calculateDistance(office, house) == 5.0);
    CHECK(transport.calculateDistance(flat, factory) == 5.0);

    transport.travel(flat, factory);
    transport.travel(house, office);
}

TEST_CASE("TrafficManager Class Tests") {
    TrafficManager trafficManager;

    auto factory = std::make_shared<Factory>(100, "cotton", 300);
    auto flat = std::make_shared<Flat>(100, 150, 5, false); 
    auto house = std::make_shared<House>(2, true, 4, 2, true);
    auto office = std::make_shared<Office>(250, "technology"); 

    trafficManager.updateTraffic(flat, factory, 10);
    CHECK(trafficManager.isCongested(flat, factory) == false);
    
    trafficManager.incrementTraffic(flat, factory);
    CHECK(trafficManager.isCongested(flat, factory) == false); 

    trafficManager.updateTraffic(flat, factory, 90);
    CHECK(trafficManager.isCongested(house, office) == true);

    trafficManager.decreaseTraffic(flat, factory);
    CHECK(trafficManager.isCongested(house, office) == false); 
}
