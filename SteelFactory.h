#ifndef STEELFACTORY_H
#define STEELFACTORY_H

class SteelFactory : ResourceFactory {


public:
	Resource* createResource(int quantity);
};

#endif
