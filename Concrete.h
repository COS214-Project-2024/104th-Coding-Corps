#ifndef CONCRETE_H
#define CONCRETE_H

class Concrete : Resource {

public:
	int quantity;

	string getName();

	int getQuantity();

	void addQuantity();

	void consume();
};

#endif
