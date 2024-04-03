#include <catch2/catch_all.hpp>

#define TEST_NAME "[Random]"

#include <iostream>
#include <string>

#include "../TestRunner.hpp"

#include "../../../Simulation/Features/Random.hpp"

TEST_CASE("Random should generate number", TEST_NAME) {
	printStartTest(TEST_NAME);

	int testNumber = Random::getRandomNumber(0, 10);
	REQUIRE((testNumber >= 0 && testNumber <= 10));
}


TEST_CASE("Arguments for generator should be greater or equal than 0", TEST_NAME) {
	printStartTest(TEST_NAME);

	int firstTestNumber = 6;
	int secondTestNumber = -1;
	REQUIRE(firstTestNumber >= 0);
	REQUIRE_FALSE(secondTestNumber >= 0);
}