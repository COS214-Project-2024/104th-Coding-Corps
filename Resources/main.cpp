#include "ConcreteFactory.h"
#include "SteelFactory.h"
#include "WoodFactory.h"
#include "ResourceManager.h"
#include "Budget.h"
#include <iostream>
using namespace std;

int main() {
    /*******************************************/
    /*      TESTING Resource Creation (Factory Pattern)   */
    /*******************************************/
    std::cout << "=== Testing Resource Creation (Factory Pattern) ===" << std::endl;
    
    // Create factories for each resource type
    ConcreteFactory concreteFactory;
    SteelFactory steelFactory;
    WoodFactory woodFactory;

    // Create resources using the factories
    std::unique_ptr<Resource> concrete = concreteFactory.createResource(500);
    std::unique_ptr<Resource> steel = steelFactory.createResource(300);
    std::unique_ptr<Resource> wood = woodFactory.createResource(200);

    // Display resource names and quantities
    std::cout << "Resource: " << concrete->getName() << ", Quantity: " << concrete->getQuantity() << std::endl;
    std::cout << "Resource: " << steel->getName() << ", Quantity: " << steel->getQuantity() << std::endl;
    std::cout << "Resource: " << wood->getName() << ", Quantity: " << wood->getQuantity() << std::endl;

    // Simulate consumption of resources
    if (concrete->consume(100)) {
        std::cout << "Consumed 100 units of Concrete. Remaining: " << concrete->getQuantity() << std::endl;
    } else {
        std::cout << "Not enough Concrete to consume!" << std::endl;
    }

    // Add more wood
    wood->addQuantity(50);
    std::cout << "Added 50 units of Wood. New quantity: " << wood->getQuantity() << std::endl;

    std::cout << "\n=== End of Resource Creation Testing ===\n" << std::endl;

    /*******************************************/
    /*      TESTING ResourceManager (Singleton + Factory)   */
    /*******************************************/
    std::cout << "=== Testing ResourceManager (Singleton + Factory) ===" << std::endl;

    // Get the singleton instance of the ResourceManager
    auto resourceManager = ResourceManager::getInstance();

    // Add resources to the ResourceManager
    resourceManager->addResource("Concrete", 500, concreteFactory);
    resourceManager->addResource("Steel", 300, steelFactory);
    resourceManager->addResource("Wood", 200, woodFactory);

    // Display all resources
    resourceManager->displayResources();

    // Consume some resources
    resourceManager->consumeResource("Concrete", 100);
    resourceManager->consumeResource("Steel", 50);

    // Check if resources are available
    if (resourceManager->isResourceAvailable("Wood", 150)) {
        std::cout << "Enough Wood available!" << std::endl;
    } else {
        std::cout << "Not enough Wood!" << std::endl;
    }

    // Try consuming more resources than available
    resourceManager->consumeResource("Steel", 500); // Should fail due to insufficient resources

    // Display the final resources
    resourceManager->displayResources();

    // Test adding more resources and consuming them
    resourceManager->addResource("Wood", 300, woodFactory);
    resourceManager->consumeResource("Wood", 400); // Should succeed now after adding more wood
    resourceManager->displayResources();

    std::cout << "\n=== End of ResourceManager Testing ===\n" << std::endl;

    /*******************************************/
    /*      TESTING Budget (Singleton)          */
    /*******************************************/
    std::cout << "=== Testing Budget (Singleton) ===" << std::endl;

    // Get the singleton instance of the Budget
    std::shared_ptr<Budget> cityBudget = Budget::getInstance();

    // Add some revenue
    cityBudget->addRevenue(10000);

    // Attempt to deduct an expense
    cityBudget->deductExpense(2500); // Deducts 2500, successful
    cityBudget->deductExpense(8000); // Deducts 8000, successful
    cityBudget->deductExpense(2000); // Fails, insufficient funds

    // Print the final balance
    std::cout << "Final Budget Balance: $" << cityBudget->getBalance() << std::endl;

    // Print transaction history
    cityBudget->printTransactionHistory();

    // Add more revenue and test again
    cityBudget->addRevenue(5000);
    cityBudget->deductExpense(3000); // Should succeed
    cityBudget->printTransactionHistory();

    std::cout << "\n=== End of Budget Testing ===\n" << std::endl;

    /*******************************************/
    /*      TESTING Singleton Behavior          */
    /*******************************************/
    std::cout << "=== Testing Singleton Behavior ===" << std::endl;

    // Get another instance of the ResourceManager (should be the same as the original)
    auto anotherResourceManager = ResourceManager::getInstance();
    anotherResourceManager->displayResources(); // Should show the same resources

    // Get another instance of Budget (should be the same instance)
    std::shared_ptr<Budget> anotherBudgetInstance = Budget::getInstance();
    std::cout << "Current Budget Balance (from another instance): $" << anotherBudgetInstance->getBalance() << std::endl;

    std::cout << "\n=== End of Singleton Testing ===\n" << std::endl;

    return 0;
}
