#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager {

private:
	map<null, Resource*> resources;
	ResourceManager* instance;

	ResourceManager();

public:
	void ReaourceManager(int const_ResourceManager);

	void operator=(int const_ResourceManager);

	ResourceManager* getInstance();

	void addResource(string& type, int quantity, const ResourceFactory factory);

	Resource* getResource(string& type);
};

#endif
