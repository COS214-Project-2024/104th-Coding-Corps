#include "ResourceManager.h"
#include <iostream>

std::shared_ptr<ResourceManager> ResourceManager::instance = nullptr;

/**
 * @brief Get the singleton instance of ResourceManager.
 * 
 * This method returns the single instance of ResourceManager. If the instance 
 * does not exist, it creates one.
 * 
 * @return A shared pointer to the ResourceManager instance.
 */
std::shared_ptr<ResourceManager> ResourceManager::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<ResourceManager>(new ResourceManager());
    }
    return instance;
}

/**
 * @brief Add a resource to the ResourceManager.
 * 
 * This method adds a specified quantity of a resource to the ResourceManager. 
 * If the resource already exists, its quantity is increased. If it does not 
 * exist, it creates a new resource using the provided factory.
 * 
 * @param type The type of the resource to add.
 * @param quantity The quantity of the resource to add.
 * @param factory The resource factory used to create the resource if it does not exist.
 */
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

/**
 * @brief Get a resource from the ResourceManager.
 * 
 * This method retrieves a shared pointer to the specified resource type.
 * 
 * @param type The type of the resource to retrieve.
 * @return A shared pointer to the resource if found; otherwise, nullptr.
 */
std::shared_ptr<Resource> ResourceManager::getResource(const std::string& type) {
    if (resources.find(type) != resources.end()) {
        return resources[type];
    }
    std::cerr << "Resource of type " << type << " not found." << std::endl;
    return nullptr; 
}

/**
 * @brief Consume a specified quantity of a resource.
 * 
 * This method attempts to consume a specified quantity of the given resource type. 
 * If the resource is available and the consumption is successful, it returns true; 
 * otherwise, it returns false.
 * 
 * @param type The type of the resource to consume.
 * @param quantity The quantity of the resource to consume.
 * @return true if the resource was successfully consumed, false otherwise.
 */
bool ResourceManager::consumeResource(const std::string& type, int quantity) {
    auto resource = getResource(type);
    if (resource && resource->consume(quantity)) {
        std::cout << "Consumed " << quantity << " units of " << type << "." << std::endl;
        return true;
    }
    std::cerr << "Failed to consume " << quantity << " units of " << type << ". Not enough resources." << std::endl;
    return false;
}

/**
 * @brief Check if a specified quantity of a resource is available.
 * 
 * This method checks whether the specified quantity of the given resource type is 
 * available in the ResourceManager.
 * 
 * @param type The type of the resource to check.
 * @param quantity The quantity to check for availability.
 * @return true if the resource is available, false otherwise.
 */
bool ResourceManager::isResourceAvailable(const std::string& type, int quantity) {
    auto resource = getResource(type);
    if (resource) {
        return resource->checkAvailability(quantity);
    }
    return false;
}

/**
 * @brief Display the current resources in the ResourceManager.
 * 
 * This method prints out the current inventory of resources, including their types 
 * and quantities.
 */
void ResourceManager::displayResources() const {
    std::cout << "\n--- Resource Inventory ---" << std::endl;
    for (const auto& [type, resource] : resources) {
        std::cout << "Resource: " << type << ", Quantity: " << resource->getQuantity() << std::endl;
    }
    std::cout << "--- End of Inventory ---\n" << std::endl;
}
