#include "WoodFactory.h"

/**
 * @brief Creates a unique pointer to a Wood resource.
 * 
 * @param quantity The amount of wood to be created.
 * @return A unique pointer to a Wood resource with the specified quantity.
 */
std::unique_ptr<Resource> WoodFactory::createResource(int quantity) {
    return std::make_unique<Wood>(quantity);
}
