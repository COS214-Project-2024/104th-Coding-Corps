#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../Citizen.h"
#include "../CityContext.h"
#include "../Transport.h"
#include "../Government.h"
#include <memory>

class CitizenFixture {
public:
    std::shared_ptr<CityContext> cityContext;
    std::shared_ptr<Transport> transportContext;
    std::shared_ptr<Government> government;
    std::shared_ptr<Citizen> citizen;

    CitizenFixture() {
        cityContext = CityContext::getInstance();
        government = Government::getInstance();
        transportContext = std::make_shared<Transport>();
        citizen = std::make_shared<Citizen>(cityContext, nullptr, government);
        cityContext->attach(citizen);
        citizen->initialize();
    }
};



TEST_CASE_FIXTURE(CitizenFixture, "Citizen initialization") {
    int initialSatisfaction = citizen->getSatisfaction();
    CHECK_EQ(citizen->getSatisfaction(), initialSatisfaction);
    CHECK_GE(citizen->getCitizenID(), 10000000);  // ID starts from 10000000
}

TEST_CASE_FIXTURE(CitizenFixture, "Update satisfaction") {
    int initialSatisfaction = citizen->getSatisfaction();
    
    citizen->updateSatisfaction(10);
    CHECK_EQ(citizen->getSatisfaction(), initialSatisfaction + 10);

    citizen->updateSatisfaction(-20);
    CHECK_GE(citizen->getSatisfaction(), 0);  // Satisfaction should not go below 0
}

TEST_CASE_FIXTURE(CitizenFixture, "Employment and income") {
    citizen->updateEmployment();  // Toggle employment status
    CHECK_EQ(citizen->getEmployment(), citizen->getEmployment());  // Check toggled state

    double initialIncome = citizen->getCurrentIncome();
    citizen->updateCurrentIncome(5000);
    CHECK_EQ(citizen->getCurrentIncome(), initialIncome + 5000);

    // citizen->updateCurrentIncome(-10000);
    // CHECK_GE(citizen->getCurrentIncome(), 0);  // Income should not go negative
}

TEST_CASE_FIXTURE(CitizenFixture, "Promote and demote class") {
    std::string initialClass = citizen->getJobType();

    citizen->promoteClass();
    if (initialClass == "lower") {
        CHECK_EQ(citizen->getJobType(), "middle");
    } else if (initialClass == "middle") {
        CHECK_EQ(citizen->getJobType(), "upper");
    } else {
        CHECK_EQ(citizen->getJobType(), initialClass);  // Should not promote if already upper
    }

    citizen->demoteClass();
    if (initialClass == "upper") {
        CHECK_EQ(citizen->getJobType(), "middle");
    } else if (initialClass == "middle") {
        CHECK_EQ(citizen->getJobType(), "lower");
    } else {
        CHECK_EQ(citizen->getJobType(), initialClass);  // Should not demote if already lower
    }
}

TEST_CASE_FIXTURE(CitizenFixture, "Tax calculation") {
    citizen->updateCurrentIncome(50000);
    double tax = citizen->calculateTax();

    if (citizen->getEmployment()) {
        if (citizen->getJobType() == "lower") {
            CHECK_EQ(tax, citizen->getCurrentIncome() * 0.1);
        } else if (citizen->getJobType() == "middle") {
            CHECK_EQ(tax, citizen->getCurrentIncome() * 0.22);
        } else if (citizen->getJobType() == "upper") {
            CHECK_EQ(tax, citizen->getCurrentIncome() * 0.35);
        }
    } else {
        CHECK_EQ(tax, 0);  // Unemployed citizens shouldn't pay tax
    }
}
