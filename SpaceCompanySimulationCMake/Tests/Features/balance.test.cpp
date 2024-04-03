#include <catch2/catch_all.hpp>

#define TEST_NAME "[Balance]"

#include <iostream>
#include <string>

#include "../TestRunner.hpp"

#include "../../../Simulation/Features/Balance.hpp"

SCENARIO("Balance instance should be created and initialised", TEST_NAME) {
	printStartTest(TEST_NAME);

	GIVEN("testNumber given") {
		int testNumber = 100;
		WHEN("Balance created") {
			Balance testBalance(testNumber);

			THEN("Value from getBalance should be equal as testNumber") {
				REQUIRE(testBalance.getBalance() == testNumber);
			}
		}
	}
}

SCENARIO("checkBalance should return correct BOOL", TEST_NAME) {
	printStartTest(TEST_NAME);
	
	SECTION("Positive Value") {
		GIVEN("Balance instance created with positive value") {
			Balance testBalance(100);
			THEN("It should return TRUE") {
				REQUIRE(testBalance.checkBalance());
			}
		}
	}

	SECTION("Negative Value") {
		GIVEN("Balance instance created with negative value") {
			Balance testBalance(-100);
			THEN("It should return FALSE") {
				REQUIRE_FALSE(testBalance.checkBalance());
			}
		}
	}
}

SCENARIO("updateBalance should return correct BOOL and update value", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Positive Value") {
		GIVEN("Balance instance created with positive value") {
			int testNumber = 100;
			int testNumberToUpdate = 50;
			Balance testBalance(testNumber);
			WHEN("updateBalance called") {
				bool testOutput = testBalance.updateBalance(testNumberToUpdate);
				THEN("It should correctly update Balance") {
					REQUIRE(testBalance.getBalance() == (testNumber + testNumberToUpdate));
				}
				AND_THEN("and return correct BOOL") {
					REQUIRE(testOutput);
				}
			}
		}
	}

	SECTION("Negative Value") {
		GIVEN("Balance instance created with negative value") {
			int testNumber = 100;
			int testNumberToUpdate = -200;
			Balance testBalance(testNumber);
			WHEN("updateBalance called") {
				bool testOutput = testBalance.updateBalance(testNumberToUpdate);
				THEN("It should correctly update Balance") {
					REQUIRE(testBalance.getBalance() == (testNumber + testNumberToUpdate));
				}
				AND_THEN("and return correct BOOL") {
					REQUIRE_FALSE(testOutput);
				}
			}
		}
	}
}