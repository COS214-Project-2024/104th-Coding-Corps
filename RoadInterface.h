#ifndef ROADINTERFACE_H
#define ROADINTERFACE_H

class RoadInterface {

private:
	TrafficManagerInterface* observerList;

public:
	void attach(TrafficManagerInterface* o);

	void detach(TrafficManagerInterface* o);

	void notifyObservers();
};

#endif
