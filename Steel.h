#ifndef STEEL_H
#define STEEL_H

class Steel : Resource {

public:
	int quantity;

	string getName();

	int getQuantity();

	void addQuantity();

	void consume();
};

#endif
