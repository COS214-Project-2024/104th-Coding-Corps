#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../CityContext.h"
#include "../SavePoint.h"
#include "../SavePointManager.h"
#include "../Government.h"
#include "../Citizen.h"
#include "../BuildingComponent.h"
#include "../Utilities.h"
#include <memory>

TEST_SUITE("Memento Pattern Tests") {
    
    std::shared_ptr<CityContext> cityContext = CityContext::getInstance();
    std::shared_ptr<Government> government = Government::getInstance();

    // Helper function to create a save point from the CityContext's current state
    std::shared_ptr<SavePoint> createSavePoint() {
        return cityContext->saveGame();
    }

    // SavePoint Tests
    TEST_CASE("SavePoint: Save and Restore State") {
        // Initial Setup - Attach a citizen, add a building, and add a utility
        auto citizen = std::make_shared<Citizen>(cityContext, nullptr, government);
        cityContext->attach(citizen);
        citizen->initialize();

        // auto building = std::make_shared<BuildingComponent>(/* args */); // Replace with actual constructor args
        // cityContext->addBuilding(building);

        // auto utility = std::make_shared<Utilities>(/* args */); // Replace with actual constructor args
        // cityContext->addUtility(utility);

        // cityContext->calculateAverages();
         int originalPop = cityContext->calculateTotalPop();
        // int originalBuildings = cityContext->calculateTotalBuildings();
        // int originalUtilities = cityContext->countTotalUtilities();

        // // Create a save point
         auto savePoint = createSavePoint();

        // // Make changes to CityContext
         cityContext->detach(citizen);
        // cityContext->removeBuilding(building);
        // cityContext->removeUtility(utility);

        // // Check that state has changed
         CHECK(cityContext->calculateTotalPop() == originalPop - 1);
        // CHECK(cityContext->calculateTotalBuildings() == originalBuildings - 1);
        // CHECK(cityContext->countTotalUtilities() == originalUtilities - 1);

        // // Restore to saved state
         cityContext->setSavePoint(savePoint);

        // // Verify restoration to saved state
         CHECK(cityContext->calculateTotalPop() == originalPop);
        // CHECK(cityContext->calculateTotalBuildings() == originalBuildings);
        // CHECK(cityContext->countTotalUtilities() == originalUtilities);
    }

    // SavePointManager Tests
    TEST_CASE("SavePointManager: Undo and Redo Operations") {
        SavePointManager manager;
        
        // Initial save state
        auto initialSave = createSavePoint();
        manager.saveState(initialSave);
        int initialPop = cityContext->calculateTotalPop();

        // Make some changes and save them
        auto newCitizen = std::make_shared<Citizen>(cityContext, nullptr, government);
        cityContext->attach(newCitizen);
        newCitizen->initialize();
        auto modifiedSave = createSavePoint();
        manager.saveState(modifiedSave);

        // Check current state matches modified save
        //CHECK(cityContext->calculateTotalPop() == initialSave->totalPopulation + 1);

        // Undo back to initial state
        auto undoSave = manager.undo();
        cityContext->setSavePoint(undoSave);

        // Verify state matches initial save point
        //CHECK(cityContext->calculateTotalPop() == initialSave->totalPopulation);

        // Redo back to modified state
        auto redoSave = manager.redo();
        cityContext->setSavePoint(redoSave);

        // Verify state matches modified save point
       // CHECK(cityContext->calculateTotalPop() == modifiedSave->totalPopulation);
    }

    TEST_CASE("SavePointManager: Clear All Save Points") {
        SavePointManager manager;

        // Create and save initial state
        auto initialSave = createSavePoint();
        manager.saveState(initialSave);

        // Add a new save point after modifying the context
        auto newCitizen = std::make_shared<Citizen>(cityContext, nullptr, government);
        cityContext->attach(newCitizen);
        newCitizen->initialize();
        auto modifiedSave = createSavePoint();
        manager.saveState(modifiedSave);

        // Ensure there are save points in the manager
        CHECK(manager.undo() != nullptr);
        CHECK(manager.redo() != nullptr);

        // Clear all save points
        manager.clear();

        // Test that undo and redo return nullptr after clearing
        CHECK(manager.undo() == nullptr);
        CHECK(manager.redo() == nullptr);
    }
}
