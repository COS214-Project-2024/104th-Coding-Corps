#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H

class ResourceFactory {

private:
	Resource* resource;

public:
	Resource* createResource(int quantity);
};

#endif
