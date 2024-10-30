#include "WoodFactory.h"

std::unique_ptr<Resource> WoodFactory::createResource(int quantity) {
	return std::make_unique<Wood>(quantity);
}