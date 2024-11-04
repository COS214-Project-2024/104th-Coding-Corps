#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

// Include all dependencies from the dependencies folder
#include "../ResourceManager.h"
#include "../ResourceFactory.h"
#include "../AbstractCitizen.h"
#include "../Budget.h"
#include "../BuildingComposite.h"
#include "../BuildingComponent.h"   // New stub
#include "../Utilities.h"           // New stub
#include "../Government.h"
#include "../Command.h"
#include "../WoodFactory.h"

// Mock classes for dependencies if needed
class MockResourceManager : public ResourceManager {
public:
    bool consumeResource(const std::string& type, int quantity) {
        return true; // Stub behavior
    }
    void addResource(const std::string& type, int quantity) {}
    void displayResources() const {}
};

class MockBudget : public Budget {
public:
    void addRevenue(double amount) {}
    bool deductExpense(double amount) { return true; }
};

class MockCommand : public Command {
public:
    bool executed = false;
    void execute() override {
        executed = true;  // Simulate command execution
    }
};

// Test for singleton instance
TEST_CASE("Testing Government Singleton") {
    auto gov1 = Government::getInstance();
    auto gov2 = Government::getInstance();
    CHECK(gov1 == gov2);  // Both instances should be the same
}

// Test budget increase and decrease
TEST_CASE("Testing budget increase and decrease") {
    auto gov = Government::getInstance();
    gov->increaseBudget(5000);
    CHECK(gov->getBalance() == 5000);  // Mock: Assume the balance is correctly updated

    gov->decreaseBudget(2000);
    CHECK(gov->getBalance() == 3000);
}

// Test resource addition and notification to citizens
TEST_CASE("Testing addResourceToCity and notifyResourceChange") {
    auto gov = Government::getInstance();
    ResourceFactory* factory = new WoodFactory();  // Assuming this is in dependencies
    gov->addResourceToCity("Wood", 1000, *factory);  // Add resources
    gov->displayCityResources();
}

// Test resource consumption
TEST_CASE("Testing useResource") {
    auto gov = Government::getInstance();
    CHECK(gov->useResource("Wood", 50) == true);  // Mock resource consumption
}

// Test command execution
TEST_CASE("Testing setCommand and issueCommand") {
    auto gov = Government::getInstance();
    auto command = std::make_shared<MockCommand>();  // Use a shared_ptr for compatibility

    gov->setCommand(command);
    gov->issueCommand();
    CHECK(command->executed == true);  // Check if command was executed
}