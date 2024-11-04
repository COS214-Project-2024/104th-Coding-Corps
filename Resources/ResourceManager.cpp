#include "ResourceManager.h"
#include <iostream>


std::shared_ptr<ResourceManager> ResourceManager::instance = nullptr;

std::shared_ptr<ResourceManager> ResourceManager::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<ResourceManager>(new ResourceManager());
    }
    return instance;
}


void ResourceManager::addResource(const std::string& type, int quantity, ResourceFactory& factory) {
    if (resources.find(type) != resources.end()) {
       
        auto& existingResource = resources[type];
        existingResource->addQuantity(quantity); 
        std::cout << "Increased " << quantity << " units of " << type << " in the ResourceManager." << std::endl;
    } else {
 
        auto resource = factory.createResource(quantity);
        resources[type] = std::move(resource);
        std::cout << "Added " << quantity << " units of " << type << " to the ResourceManager." << std::endl;
    }
}

std::shared_ptr<Resource> ResourceManager::getResource(const std::string& type) {
    if (resources.find(type) != resources.end()) {
        return resources[type];
    }
    std::cerr << "Resource of type " << type << " not found." << std::endl;
    return nullptr; 
}

bool ResourceManager::consumeResource(const std::string& type, int quantity) {
    auto resource = getResource(type);
    if (resource && resource->consume(quantity)) {
        std::cout << "Consumed " << quantity << " units of " << type << "." << std::endl;
        return true;
    }
    std::cerr << "Failed to consume " << quantity << " units of " << type << ". Not enough resources." << std::endl;
    return false;
}

bool ResourceManager::isResourceAvailable(const std::string& type, int quantity) {
    auto resource = getResource(type);
    if (resource) {
        return resource->checkAvailability(quantity);
    }
    return false;
}

void ResourceManager::displayResources() const {
    std::cout << "\n--- Resource Inventory ---" << std::endl;
    for (const auto& [type, resource] : resources) {
        std::cout << "Resource: " << type << ", Quantity: " << resource->getQuantity() << std::endl;
    }
    std::cout << "--- End of Inventory ---\n" << std::endl;
}



