#ifndef WATER_H
#define WATER_H

class Water : Resource {

public:
	int quantity;

	string getName();

	int getQuantity();

	void addQuantity();

	void consume();
};

#endif
