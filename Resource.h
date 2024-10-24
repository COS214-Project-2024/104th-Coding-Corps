#ifndef RESOURCE_H
#define RESOURCE_H

class Resource {


public:
	virtual string getName() = 0;

	virtual int getQuantity() = 0;

	virtual void addQuantity() = 0;

	virtual void consume() = 0;
};

#endif
