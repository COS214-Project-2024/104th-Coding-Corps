#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Transport.h"
#include "TrafficManager.h"
#include "House.h"
#include "Factory.h"
#include <string>

TEST_CASE("Transport Class Tests") {

   auto house = std::make_shared<House>(10, 20, "Residential District", 5, 30, true, 4, 2, true);

    auto factory1 = std::make_shared<factory>(15, 25, "Industrial Area", 5, 50, "Manufacturing", 1000.0); // x = 15, y = 25

    Transport transport;

    SUBCASE("Calculate Distance") {
    
        double distance = transport.calculateDistance(house, factory1);
        CHECK(distance == doctest::Approx(7.071).epsilon(0.01)); // Expected distance based on (10, 20) and (15, 25)
    }

    SUBCASE("Choose Strategy - Walking") {
        transport.chooseStrategy(0.5, false); // Less than 1km, not congested
        CHECK(transport.getCurrentStrategy()->getMode() == "Walking");
    }

    SUBCASE("Choose Strategy - Car") {
 
        transport.chooseStrategy(5.0, false); // 5km, not congested
        CHECK(transport.getCurrentStrategy()->getMode() == "Car");
    }

    SUBCASE("Choose Strategy - Bus") {
        transport.chooseStrategy(5.0, true); // 5km, congested
        CHECK(transport.getCurrentStrategy()->getMode() == "Bus");
    }

    SUBCASE("Choose Strategy - Train") {

        transport.chooseStrategy(15.0, false); // 15km, not congested
        CHECK(transport.getCurrentStrategy()->getMode() == "Train");
    }

    SUBCASE("Complete Travel") {
        transport.travel(house, factory1); // This will trigger completeTravel internally
        CHECK(transport.getTrafficManager()->isCongested(house, factory1) == false); // Assuming it's not congested
    }

    SUBCASE("Calculate Commute Time") {
        // Assume we can directly test calculateCommuteTime if it's exposed in TransportStrategy
        double distance = 10.0; // Example distance
        transport.chooseStrategy(distance, false);
        double commuteTime = transport.getCurrentStrategy()->calculateCommuteTime(distance);
        CHECK(commuteTime == doctest::Approx(0.1667).epsilon(0.01)); // Example check based on speed and distance
    }
}


TEST_CASE("TrafficManager Tests") {
    TrafficManager trafficManager;
    
   auto house = std::make_shared<House>(10, 20, "Residential District", 5, 30, true, 4, 2, true);

    auto factory1 = std::make_shared<factory>(15, 25, "Industrial Area", 5, 50, "Manufacturing", 1000.0); // x = 15, y = 25

    SUBCASE("Check initial congestion status") {
        CHECK(!trafficManager.isCongested(house, factory1));
    }

    SUBCASE("Update traffic level and check congestion") {
        trafficManager.updateTraffic(house, factory1, 85);
        CHECK(trafficManager.isCongested(house, factory1));
        
        trafficManager.updateTraffic(house, factory1, 70);
        CHECK(!trafficManager.isCongested(house, factory1));
    }

    SUBCASE("Increment traffic and check levels") {
        trafficManager.incrementTraffic(house, factory1);
        CHECK(trafficManager.isCongested(house, factory1) == false); // 1 < 80

        for (int i = 0; i < 79; ++i) {
            trafficManager.incrementTraffic(house, factory1);
        }
        CHECK(trafficManager.isCongested(house, factory1) == false); // 80 < 80

        trafficManager.incrementTraffic(house, factory1);
        CHECK(trafficManager.isCongested(house, factory1) == true); // 81 > 80
    }

    SUBCASE("Decrease traffic levels") {
        trafficManager.updateTraffic(house, factory1, 90);
        CHECK(trafficManager.isCongested(house, factory1));

        trafficManager.decreaseTraffic(house, factory1);
        CHECK(trafficManager.isCongested(house, factory1)); // 89 > 80

        for (int i = 0; i < 10; ++i) {
            trafficManager.decreaseTraffic(house, factory1);
        }
        CHECK(trafficManager.isCongested(house, factory1)); // 79 < 80
    }

    SUBCASE("Check non-existent traffic levels") {
        CHECK(trafficManager.isCongested(house, factory1) == false); // Should return false since no traffic level set
        trafficManager.decreaseTraffic(house, factory1); // Should not crash
    }
}
