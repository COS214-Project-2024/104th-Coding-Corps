#ifndef BUDGET_H
#define BUDGET_H
#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Budget {

private:
	double balance;
	static shared_ptr<Budget> instance;
	vector<string> transactionHistory; 

	Budget(): balance(0.0){};

public:

    Budget(const Budget&) = delete;
    void operator=(const Budget&) = delete;
	static shared_ptr<Budget> getInstance();
	void addRevenue(double amount);
	bool deductExpense(double amount);
	double getBalance() const;
	void logTransaction(const std::string& transaction);
	void printTransactionHistory() const;
};

#endif
