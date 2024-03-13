#pragma once

class Balance {
private:
	int __balance;

public:
	Balance(int balance) : __balance(balance) {};

	const int getBalance() { return __balance; }

	const bool checkBalance() { return __balance >= 0 ? true : false; }

	const bool updateBalance(const int value) { __balance += value; return checkBalance(); }
};