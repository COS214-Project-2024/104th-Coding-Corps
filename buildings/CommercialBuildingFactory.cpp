#include "CommercialBuildingFactory.h"
#include "Office.h"
#include "mall.h"
#include "Shop.h"

BuildingComponent* CommercialBuildingFactory::createOffice(int numEmployees, string businessType){
	return new Office(numEmployees, businessType);
}
BuildingComponent* CommercialBuildingFactory::createMall(int numShops, string businessType, int numBusinesses){
	return new Mall(numShops, businessType, numBusinesses);
}
BuildingComponent* CommercialBuildingFactory::createShop(int shopSize, string businessType) {
	return new Shop(shopSize, businessType);
}