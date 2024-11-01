#include "Resource.h"

/**
 * @brief Get the current quantity of the resource.
 * 
 * This method retrieves the current quantity of the resource.
 * 
 * @return The current quantity of the resource.
 */
int Resource::getQuantity() const {
    return quantity;
}

/**
 * @brief Add a specified amount to the resource's quantity.
 * 
 * This method increases the current quantity of the resource by the 
 * specified amount.
 * 
 * @param amount The amount to add to the resource's quantity.
 */
void Resource::addQuantity(int amount) {
    quantity += amount;
}

/**
 * @brief Consume a specified amount of the resource if available.
 * 
 * This method attempts to reduce the resource's quantity by the specified 
 * amount. If sufficient quantity is available, it decreases the quantity and 
 * returns true; otherwise, it returns false.
 * 
 * @param amount The amount to consume from the resource.
 * @return true if the resource was successfully consumed, false otherwise.
 */
bool Resource::consume(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false;
}

/**
 * @brief Check if enough resource is available.
 * 
 * This method checks whether the specified amount of resource is available.
 * 
 * @param amount The amount to check for availability.
 * @return true if enough resource is available, false otherwise.
 */
bool Resource::checkAvailability(int amount) const {
    return quantity >= amount;
}
