#include "Budget.h"
#include <iomanip>

std::shared_ptr<Budget> Budget::instance = nullptr;

std::shared_ptr<Budget> Budget::getInstance() {
    if (!instance) {
        instance = std::shared_ptr<Budget>(new Budget());
    }
    return instance;
}

void Budget::addRevenue(double amount) {
    balance += amount;
    logTransaction("Added revenue: R" + std::to_string(amount));
    std::cout << "Added R" << amount << " to the budget. Current balance: R" << balance <<std::setprecision(2)<< std::endl;
}

// Deduct expense from the budget
bool Budget::deductExpense(double amount) {
    if (balance >= amount) {
        balance -= amount;
        logTransaction("Deducted expense: R" + std::to_string(amount));
        std::cout << "Deducted R" << amount << " from the budget. Current balance: R" << balance << std::endl;
        return true;
    } else {
        std::cout << "Insufficient funds! Cannot deduct R" << amount << ". Current balance: R" << balance << std::endl;
        logTransaction("Failed to deduct expense due to insufficient funds: $" + std::to_string(amount));
        return false;
    }
}


double Budget::getBalance() const {
    return balance;
}

// Log each transaction for auditing purposes
void Budget::logTransaction(const std::string& transaction) {
    transactionHistory.push_back(transaction);
}

// Print the transaction history
void Budget::printTransactionHistory() const {
    std::cout << "\n--- Transaction History ---\n";
    for (const std::string& entry : transactionHistory) {
        std::cout << entry << std::endl;
    }
    std::cout << "--- End of History ---\n";
}


