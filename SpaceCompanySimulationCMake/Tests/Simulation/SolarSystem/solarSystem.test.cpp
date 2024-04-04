#include <catch2/catch_all.hpp>

#define TEST_NAME "[SolarSystem]"

#include <iostream>
#include <string>
#include <vector>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/SolarSystem.hpp"

TEST_CASE("Create Solar System", TEST_NAME) {
	printStartTest(TEST_NAME);

	SolarSystem* sol = new SolarSystem();

	SECTION("Comparing sizes") {
		REQUIRE(sol->planets.size() == 7);
		REQUIRE(sol->asteroidClusters.size() == 3);
		REQUIRE(sol->star->name == "Sun");
	}

	SECTION("Comparing ID's of objects") {
		REQUIRE(sol->planets[0]->_id == 1);
		REQUIRE(sol->planets[3]->_id == 4);
		REQUIRE(sol->planets[6]->_id == 7);
		REQUIRE(sol->asteroidClusters[0]->name == "Asteroid Belt");
		REQUIRE(sol->asteroidClusters[2]->name == "Kuiper Belt");
		REQUIRE(sol->star->_id == 0);
	}

	delete sol;
}

TEST_CASE("Methods default values", TEST_NAME) {
	printStartTest(TEST_NAME);

	SolarSystem* sol = new SolarSystem();

	SECTION("getExploredClusters") {
		REQUIRE(sol->getExploredClusters().empty());
	}

	SECTION("isExploredClustersEmpty") {
		REQUIRE(sol->isExploredClustersEmpty());
	}

	SECTION("isEveryClusterExplored") {
		REQUIRE_FALSE(sol->isEveryClusterExplored());
	}

	delete sol;
}

SCENARIO("makeClusterExplored method") {
	printStartTest(TEST_NAME);

	SECTION("Create Solar System") {
		SolarSystem* sol = new SolarSystem();

		GIVEN("First cluster of the vector") {
			auto testCluster = sol->asteroidClusters[0];
			WHEN("makeClusterExplored called") {
				sol->makeClusterExplored(testCluster);
				THEN("Cluster should be explored") {
					testCluster->clusterStatus == AsteroidStatus::EXPLORED;
				}
				WHEN("After the cluster was made explored") {
					THEN("getExploredClusters should return this cluster") {
						REQUIRE(sol->getExploredClusters()[0] == testCluster);
					}
					AND_THEN("isExploredClustersEmpty should return FALSE") {
						REQUIRE_FALSE(sol->isExploredClustersEmpty());
					}
					AND_THEN("isEveryClusterExplored should also return FALSE") {
						REQUIRE_FALSE(sol->isEveryClusterExplored());
					}
				}
			}
		}
		delete sol;
	}
}
