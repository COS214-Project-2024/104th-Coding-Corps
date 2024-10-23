#ifndef WOODFACTORY_H
#define WOODFACTORY_H

class WoodFactory : ResourceFactory {


public:
	Resource* createResource(int quantity);
};

#endif
