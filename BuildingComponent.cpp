#include "BuildingComponent.h"

/**
 * @brief Constructs a BuildingComponent with the specified parameters.
 * 
 * @param x The x-coordinate of the building component.
 * @param y The y-coordinate of the building component.
 * @param district The district where the building component is located.
 * @param quality The quality rating of the building component.
 */
BuildingComponent::BuildingComponent(int x, int y, const std::string& district, int quality)
        : x(x), y(y), district(district), quality(quality) {}

/**
 * @brief Gets the x-coordinate of the building component.
 * 
 * @return The x-coordinate.
 */
int BuildingComponent::getX() {
	return this->x;
}

/**
 * @brief Gets the y-coordinate of the building component.
 * 
 * @return The y-coordinate.
 */
int BuildingComponent::getY() {
	return this->y;
}

/**
 * @brief Gets the quality rating of the building component.
 * 
 * @return The quality rating.
 */
int BuildingComponent::getQuality() {
	return this->quality;
}

/**
 * @brief Gets the district where the building component is located.
 * 
 * @return The district name.
 */
std::string BuildingComponent::getDistrict() {
	return this->district;
}
