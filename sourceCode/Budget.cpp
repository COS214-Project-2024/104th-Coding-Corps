#include "Budget.h"
#include <iomanip>

/**
 * @brief Static instance of the Budget class for the Singleton pattern.
 */
std::shared_ptr<Budget> Budget::instance = nullptr;

/**
 * @brief Gets the singleton instance of the Budget class.
 * 
 * @return A shared pointer to the Budget instance.
 */
std::shared_ptr<Budget> Budget::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<Budget>(new Budget());
    }
    return instance;
}

/**
 * @brief Adds revenue to the budget and logs the transaction.
 * 
 * @param amount The amount of revenue to add.
 */
void Budget::addRevenue(double amount) {
    balance += amount;
    logTransaction("Added revenue: R" + std::to_string(amount));
    std::cout << std::fixed << std::setprecision(2);
    //std::cout << "Added R" << amount << " to the budget. Current balance: R" << balance << std::endl;
}

/**
 * @brief Deducts an expense from the budget if sufficient funds are available.
 * 
 * @param amount The amount of expense to deduct.
 * @return true if the expense was deducted successfully, false otherwise.
 */
bool Budget::deductExpense(double amount) {
    if (balance >= amount) {
        balance -= amount;
        logTransaction("Deducted expense: R" + std::to_string(amount));
        std::cout << std::fixed << std::setprecision(2);
        if(amount != 2500.00) {
            std::cout << "Deducted R" << amount << " from the budget. Current balance: R" << balance << std::endl;
            return true;
        }
    } else {
        if(amount != 2500.00) {
            std::cout << "Insufficient funds! Cannot deduct R" << amount << ". Current balance: R" << balance << std::endl;
        }
        logTransaction("Failed to deduct expense due to insufficient funds: R" + std::to_string(amount));
        return false;
    }
}

/**
 * @brief Gets the current balance of the budget.
 * 
 * @return The current balance.
 */
double Budget::getBalance() const {
    return balance;
}

void Budget::setBalance(double balance) {
    this->balance = balance;
}

/**
 * @brief Logs each transaction for auditing purposes.
 * 
 * @param transaction The transaction details to log.
 */
void Budget::logTransaction(const std::string& transaction) {
    transactionHistory.push_back(transaction);
}

/**
 * @brief Prints the transaction history to the console.
 */
void Budget::printTransactionHistory() const {
    std::cout << "\n--- Transaction History ---\n";
    for (const std::string& entry : transactionHistory) {
        std::cout << entry << std::endl;
    }
    std::cout << "--- End of History ---\n";
}
