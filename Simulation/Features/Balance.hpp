#pragma once

#include <atomic>

class Balance {
private:
	std::atomic<int> __balance;

public:
	Balance(const int balance) : __balance(balance) {};

	int getBalance() const { return __balance; }

	bool checkBalance() const { return __balance >= 0 ? true : false; }

	bool updateBalance(const int value) { __balance.fetch_add(value, std::memory_order_relaxed); return checkBalance(); }
};