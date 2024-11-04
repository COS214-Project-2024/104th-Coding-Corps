#include "SteelFactory.h"

/**
 * @brief Creates a Steel resource with the specified quantity.
 * 
 * @param quantity The amount of Steel to create.
 * @return A unique_ptr to the newly created Steel resource.
 */
std::unique_ptr<Resource> SteelFactory::createResource(int quantity, double costPerUnit) {
    return std::make_unique<Steel>(quantity,costPerUnit);
}
