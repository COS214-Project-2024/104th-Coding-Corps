#include "CommercialBuildingFactory.h"
#include "Office.h"
#include "mall.h"
#include "Shop.h"
#include <random>

/**
 * @brief Creates an Office building with randomized coordinates.
 * 
 * This function generates random x and y coordinates for the office's position
 * within a defined range and returns a unique pointer to the newly created Office object.
 * 
 * @param numEmployees The number of employees in the office.
 * @param businessType The type of business the office operates.
 * @param district The district where the office is located.
 * @param quality The quality rating of the office building.
 * @param x The x-coordinate for the office's position (overwritten).
 * @param y The y-coordinate for the office's position (overwritten).
 * @return A unique pointer to the created Office building component.
 */
std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createOffice(int numEmployees, const std::string& businessType, const std::string& district, int quality, int x, int y) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Office>(numEmployees, businessType, x, y, district, quality);
}

/**
 * @brief Creates a Mall building with randomized coordinates.
 * 
 * This function generates random x and y coordinates for the mall's position
 * within a defined range and returns a unique pointer to the newly created Mall object.
 * 
 * @param numShops The number of shops in the mall.
 * @param businessType The type of business the mall operates.
 * @param numBusinesses The number of businesses in the mall.
 * @param x The x-coordinate for the mall's position (overwritten).
 * @param y The y-coordinate for the mall's position (overwritten).
 * @param district The district where the mall is located.
 * @param quality The quality rating of the mall building.
 * @return A unique pointer to the created Mall building component.
 */
std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createMall(int numShops, const std::string& businessType, int numBusinesses, int x, int y, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Mall>(numShops, businessType, numBusinesses, x, y, district, quality);
}

/**
 * @brief Creates a Shop building with randomized coordinates.
 * 
 * This function generates random x and y coordinates for the shop's position
 * within a defined range and returns a unique pointer to the newly created Shop object.
 * 
 * @param shopSize The size of the shop.
 * @param businessType The type of business the shop operates.
 * @param x The x-coordinate for the shop's position (overwritten).
 * @param y The y-coordinate for the shop's position (overwritten).
 * @param district The district where the shop is located.
 * @param quality The quality rating of the shop building.
 * @return A unique pointer to the created Shop building component.
 */
std::unique_ptr<BuildingComponent> CommercialBuildingFactory::createShop(int shopSize, const std::string& businessType, int x, int y, const std::string& district, int quality) {
    std::mt19937 gen(static_cast<unsigned>(std::time(0))); 
    std::uniform_int_distribution<> positionDist(0, 159);
    x = positionDist(gen);
    y = positionDist(gen);
    return std::make_unique<Shop>(shopSize, businessType, x, y, district, quality);
}
