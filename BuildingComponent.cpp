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