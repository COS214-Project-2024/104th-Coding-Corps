#include "SteelFactory.h"

std::unique_ptr<Resource> SteelFactory::createResource(int quantity) {
	return std::make_unique<Steel>(quantity);
}