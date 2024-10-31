#include "BuildingComponent.h"


BuildingComponent::BuildingComponent(int x, int y, const std::string& district, int quality)
        : x(x), y(y), district(district), quality(quality) {}
		
int BuildingComponent::getX() {
	return this->x;
}

int BuildingComponent::getY() {
	return this->y;
}

int BuildingComponent::getQuality() {
	return this->quality;
}

std::string BuildingComponent::getDistrict() {
	return this->district;
}

void BuildingComponent::upgrade(std::shared_ptr<BuildingComponent> building) {
    auto government = Government::getInstance();
    
    // Example resource requirements for upgrading
    const int requiredConcrete = 100;
    const int requiredSteel = 50;

    // Request resources from Government
    bool hasConcrete = government->useResource("Concrete", requiredConcrete);
    bool hasSteel = government->useResource("Steel", requiredSteel);

    if (hasConcrete && hasSteel) {
        // Perform upgrade logic if resources are available
        quality += 10;  // Example improvement in quality
        std::cout << "Estate upgraded successfully!" << std::endl;
    } else {
        std::cout << "Upgrade failed due to insufficient resources." << std::endl;
    }
}