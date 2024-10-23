#include "ConcreteFactory.h"
std::unique_ptr<Resource> ConcreteFactory::createResource(int quantity) {
	return std::make_unique<Concrete>(quantity);
}