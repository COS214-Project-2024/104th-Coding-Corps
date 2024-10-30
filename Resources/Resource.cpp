#include "Resource.h"

// Get the current quantity of the resource
int Resource::getQuantity() const {
    return quantity;
}

// Add a specified amount to the resource's quantity
void Resource::addQuantity(int amount) {
    quantity += amount;
}

// Consume a specified amount of the resource if available
bool Resource::consume(int amount) {
    if (quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false;
}

// Check if enough resource is available
bool Resource::checkAvailability(int amount) const {
    return quantity >= amount;
}