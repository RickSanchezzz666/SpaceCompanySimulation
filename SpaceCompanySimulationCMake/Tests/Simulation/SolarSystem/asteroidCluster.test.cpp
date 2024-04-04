#include <catch2/catch_all.hpp>

#define TEST_NAME "[AsteroidCluster]"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/AsteroidCluster.hpp"

SCENARIO("Create Cluster and compare inputs", TEST_NAME) {
	printStartTest(TEST_NAME);

	GIVEN("Test inputs") {
		const std::string name = "TestCluster";
		const std::string whoseOrbitOn = "TestOrbit";
		const int diameter = 100'000;
		std::vector<std::string> asteroidType = { "C-type", "D-type" };

		WHEN("Asteroid types inputs is given") {
			THEN("Should be in strict form Example: C-type") {
				REQUIRE(asteroidType[0] == "C-type");
				REQUIRE_FALSE(asteroidType[0] == "C-Type");
				REQUIRE_FALSE(asteroidType[0] == "c-type");
			}
		}

		WHEN("Asteroid cluster created") {
			AsteroidCluster* cluster = new AsteroidCluster(name, whoseOrbitOn, diameter, asteroidType);

			THEN("Info should be equal to test") {
				REQUIRE(cluster->name == name);
				REQUIRE(cluster->whoseOrbitOn == whoseOrbitOn);
				REQUIRE(cluster->diameter == diameter);
				REQUIRE(cluster->asteroidType == asteroidType);
			}
			AND_THEN("Cluster status should be UNEXPLORED for default") {
				REQUIRE(cluster->clusterStatus == AsteroidStatus::UNEXPLORED);
			}
			AND_THEN("Asteroid components should be equal to their Type") {
				REQUIRE(std::get<0>(cluster->getAsteroidComponents()[0][0]) == "Silicon (Si)");
				REQUIRE(std::get<1>(cluster->getAsteroidComponents()[0][0]) == 45);
			}

			delete cluster;
		}
	}
}

TEST_CASE("getAsteroidComponents", TEST_NAME) {
	printStartTest(TEST_NAME);
	
	SECTION("Cluster Created") {
		const std::string name = "TestCluster";
		const std::string whoseOrbitOn = "TestOrbit";
		const int diameter = 100'000;
		std::vector<std::string> asteroidType = { "C-type", "D-type" };
		AsteroidCluster* cluster = new AsteroidCluster(name, whoseOrbitOn, diameter, asteroidType);

		std::vector<std::vector<std::tuple<std::string, int>>> testComponents = {
				{{std::make_tuple("Silicon (Si)", 45), std::make_tuple("Oxygen (O)", 25),
			std::make_tuple("Iron (Fe)", 15), std::make_tuple("Magnesium (Mg)", 10),
			std::make_tuple("Aluminum (Al)", 5)}},
				{{std::make_tuple("Silicon (Si)", 30), std::make_tuple("Oxygen (O)", 25),
			std::make_tuple("Carbon (C)", 15), std::make_tuple("Iron (Fe)", 13),
			std::make_tuple("Magnesium (Mg)", 12), std::make_tuple("Titanium (Ti)", 10)}}
		};

		WHEN("getAsteroidComponents called") {
			auto components = cluster->getAsteroidComponents();
			THEN("Components should be equal") {
				REQUIRE(components == testComponents);
			}
		}

		delete cluster;
	}
	

	

}