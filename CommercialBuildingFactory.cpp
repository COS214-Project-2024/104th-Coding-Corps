#include "CommercialBuildingFactory.h"
#include "Office.h"
#include "mall.h"
#include "Shop.h"
#include <random>

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createOffice(int numEmployees, const std::string& businessType, const std::string& district, int quality, int x, int y) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Office>(numEmployees, businessType, x, y, district, quality);
}

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createMall(int numShops, const std::string& businessType, int numBusinesses, int x, int y, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Mall>(numShops, businessType, numBusinesses, x, y, district, quality);
}

std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createShop(int shopSize, const std::string& businessType, int x, int y, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Shop>(shopSize, businessType, x, y, district, quality);
}
