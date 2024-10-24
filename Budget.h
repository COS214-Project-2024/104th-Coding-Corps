#ifndef BUDGET_H
#define BUDGET_H

class Budget {

private:
	double balance;
	Budget* instance;

	Budget();

public:
	Budget(Budget& bug);

	void operator=(Budget& bug);

	Budget* getInstance();

	void addRevenue(double amount);

	bool deductExpense(double amount);

	double getBalance();
};

#endif
