#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <string>
#include "Resource.h"
#include "ResourceFactory.h"

class ResourceManager {
private:

    std::map<std::string, std::shared_ptr<Resource>> resources;

    static std::shared_ptr<ResourceManager> instance;

    ResourceManager() = default;

public:

    ResourceManager(const ResourceManager&) = delete;
    void operator=(const ResourceManager&) = delete;

    static std::shared_ptr<ResourceManager> getInstance();

    void addResource(const std::string& type, int quantity, double costPerUnit, ResourceFactory& factory) ;

    std::shared_ptr<Resource> getResource(const std::string& type);

    bool consumeResource(const std::string& type, int quantity);

    bool isResourceAvailable(const std::string& type, int quantity);

    void displayResources() const;
};

#endif // RESOURCEMANAGER_H
