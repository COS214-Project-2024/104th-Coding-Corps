#ifndef WOOD_H
#define WOOD_H

class Wood : Resource {

public:
	int quantity;

	string getName();

	int getQuantity();

	void addQuantity();

	void consume();
};

#endif
