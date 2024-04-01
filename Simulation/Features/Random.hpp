#pragma once

#include <random>

class Random {
public:
	static int getRandomNumber(int first, int last) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(first, last);
		return dist(gen);
	}
};