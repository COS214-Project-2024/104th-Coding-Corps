#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Transport.h"
#include "TrafficManager.h"
#include "House.h"
#include "factory.h"

TEST_CASE("Transport Class Tests") {
    
    auto house = std::make_shared<House>(30, true, 10, 20, "Residential District", 5, 4, 2, true); // 30 m² garage, has pool, x = 10, y = 20, 4 residents, 2 floors, has garden
    auto factory = std::make_shared<factory>(15, 25, "Industrial Area", 5, 50, "Manufacturing", 1000.0); // x = 15, y = 25

    Transport transport;

    SUBCASE("Calculate Distance") {
    
        double distance = transport.calculateDistance(house, factory);
        CHECK(distance == doctest::Approx(7.071).epsilon(0.01)); // Expected distance based on (10, 20) and (15, 25)
    }

    SUBCASE("Choose Strategy - Walking") {
        transport.chooseStrategy(0.5, false); // Less than 1km, not congested
        CHECK(transport.currentStrategy->getMode() == "Walking");
    }

    SUBCASE("Choose Strategy - Car") {
 
        transport.chooseStrategy(5.0, false); // 5km, not congested
        CHECK(transport.currentStrategy->getMode() == "Car");
    }

    SUBCASE("Choose Strategy - Bus") {
        transport.chooseStrategy(5.0, true); // 5km, congested
        CHECK(transport.currentStrategy->getMode() == "Bus");
    }

    SUBCASE("Choose Strategy - Train") {

        transport.chooseStrategy(15.0, false); // 15km, not congested
        CHECK(transport.currentStrategy->getMode() == "Train");
    }

    SUBCASE("Complete Travel") {
        transport.travel(house, factory); // This will trigger completeTravel internally
        CHECK(transport.trafficManager->isCongested(house, factory) == false); // Assuming it's not congested
    }

    SUBCASE("Calculate Commute Time") {
        // Assume we can directly test calculateCommuteTime if it's exposed in TransportStrategy
        double distance = 10.0; // Example distance
        transport.chooseStrategy(distance, false);
        double commuteTime = transport.currentStrategy->calculateCommuteTime(distance);
        CHECK(commuteTime == doctest::Approx(0.1667).epsilon(0.01)); // Example check based on speed and distance
    }
}


TEST_CASE("TrafficManager Tests") {
    TrafficManager trafficManager;
    
    auto house = std::make_shared<House>(30, true, 10, 20, "Residential District", 5, 4, 2, true); // x = 10, y = 20
    auto factory = std::make_shared<factory>(15, 25, "Industrial Area", 5, 50, "Manufacturing", 1000.0); // x = 15, y = 25

    SUBCASE("Check initial congestion status") {
        CHECK(!trafficManager.isCongested(house, factory));
    }

    SUBCASE("Update traffic level and check congestion") {
        trafficManager.updateTraffic(house, factory, 85);
        CHECK(trafficManager.isCongested(house, factory));
        
        trafficManager.updateTraffic(house, factory, 70);
        CHECK(!trafficManager.isCongested(house, factory));
    }

    SUBCASE("Increment traffic and check levels") {
        trafficManager.incrementTraffic(house, factory);
        CHECK(trafficManager.isCongested(house, factory) == false); // 1 < 80

        for (int i = 0; i < 79; ++i) {
            trafficManager.incrementTraffic(house, factory);
        }
        CHECK(trafficManager.isCongested(house, factory) == false); // 80 < 80

        trafficManager.incrementTraffic(house, factory);
        CHECK(trafficManager.isCongested(house, factory) == true); // 81 > 80
    }

    SUBCASE("Decrease traffic levels") {
        trafficManager.updateTraffic(house, factory, 90);
        CHECK(trafficManager.isCongested(house, factory));

        trafficManager.decreaseTraffic(house, factory);
        CHECK(trafficManager.isCongested(house, factory)); // 89 > 80

        for (int i = 0; i < 10; ++i) {
            trafficManager.decreaseTraffic(house, factory);
        }
        CHECK(trafficManager.isCongested(house, factory)); // 79 < 80
    }

    SUBCASE("Check non-existent traffic levels") {
        CHECK(trafficManager.isCongested(house, factory) == false); // Should return false since no traffic level set
        trafficManager.decreaseTraffic(house, factory); // Should not crash
    }
}
