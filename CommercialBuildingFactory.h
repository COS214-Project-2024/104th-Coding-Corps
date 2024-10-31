#include <memory>
#include <string>
#include "BuildingFactory.h"
#include "BuildingComponent.h"

class CommercialBuildingFactory : public BuildingFactory {
public:
    std::unique_ptr<BuildingComponent> createOffice(int numEmployees, const std::string& businessType, int x, int y, const std::string& district, int quality) override;
    std::unique_ptr<BuildingComponent> createMall(int numShops, const std::string& businessType, int numBusinesses, int x, int y, const std::string& district, int quality) override;
    std::unique_ptr<BuildingComponent> createShop(int shopSize, const std::string& businessType, int x, int y, const std::string& district, int quality) override;
};
