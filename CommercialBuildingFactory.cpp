#include "CommercialBuildingFactory.h"
#include "Office.h"
#include "mall.h"
#include "Shop.h"

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createOffice(int numEmployees, const std::string& businessType, int x, int y, const std::string& district, int quality) {
    return std::make_unique<Office>(numEmployees, businessType, x, y, district, quality);
}

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createMall(int numShops, const std::string& businessType, int numBusinesses, int x, int y, const std::string& district, int quality) {
    return std::make_unique<Mall>(numShops, businessType, numBusinesses, x, y, district, quality);
}

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createShop(int shopSize, const std::string& businessType, int x, int y, const std::string& district, int quality) {
    return std::make_unique<Shop>(shopSize, businessType, x, y, district, quality);
}
