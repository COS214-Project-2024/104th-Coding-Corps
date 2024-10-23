#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H

class ConcreteFactory : ResourceFactory {


public:
	Resource* createResource(int quantity);
};

#endif
