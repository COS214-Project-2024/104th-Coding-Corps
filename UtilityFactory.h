#ifndef UTILITYFACTORY_H
#define UTILITYFACTORY_H

class UtilityFactory {

private:
	Utilities* utilityType;

public:
	virtual Utilities* createUtilityService() = 0;
};

#endif
