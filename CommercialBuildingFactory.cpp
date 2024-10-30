#include "CommercialBuildingFactory.h"
#include "Office.h"
#include "mall.h"
#include "Shop.h"

shared_ptr<BuildingComponent> CommercialBuildingFactory::createOffice(int numEmployees, string businessType, int x, int y, const std::string& district, int quality) {
    return make_shared<Office>(numEmployees, businessType, x, y, district, quality);
}

shared_ptr<BuildingComponent> CommercialBuildingFactory::createMall(int numShops, string businessType, int numBusinesses, int x, int y, const std::string& district, int quality) {
    return make_shared<Mall>(numShops, businessType, numBusinesses, x, y, district, quality);
}

shared_ptr<BuildingComponent> CommercialBuildingFactory::createShop(int shopSize, string businessType, int x, int y, const std::string& district, int quality) {
    return make_shared<Shop>(shopSize, businessType, x, y, district, quality);
}
