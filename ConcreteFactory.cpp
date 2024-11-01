#include "ConcreteFactory.h"

/**
 * @brief Creates a Concrete resource with the specified quantity.
 * 
 * This function generates a unique pointer to a Concrete resource,
 * initialized with the given quantity.
 * 
 * @param quantity The amount of concrete to create.
 * @return A unique pointer to the newly created Concrete resource.
 */
std::unique_ptr<Resource> ConcreteFactory::createResource(int quantity) {
    return std::make_unique<Concrete>(quantity);
}
