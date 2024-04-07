#include <catch2/catch_all.hpp>

#define TEST_NAME "[PlanetAbstract]"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/PlanetAbstract.hpp"

namespace TPlanet {
	std::string testName = "TestPlanet";
	long double testMass = 8.6810E25L;
	float testRadius = 25362.0f;
	float testDayDuration = 17.24f;
	long double testArea = 8.115E9L;
	float testOrbitalPeriod = 30685.0f;
	float testDistanceToStar = 19.22f;
	int testMaxTemperature = 76;
	int testMinTemperature = 49;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = {
		{"Hydrogen (H2)", 82.5},
		{"Methane (CH4)", 2.3},
		{"Helium (He)", 15.2}
	};
	float testGravity = 0.886f;
	int testMagneticField = 7500;
	float testLifeChance = 0.001f;
	int testMoonsNum = 4;
	std::vector<std::string> testMoons = {
		"TestMoon_1", "TestMoon_2", "TestMoon_3", "TestMoon_4"
	};
	int testId = -1;
	bool testBelt = true;
	std::string testType = "Class II gas giant";

	class TestPlanet : public PlanetAbstract {
	public:
		TestPlanet() : PlanetAbstract(testName, testMass, testRadius, testDayDuration, testArea, testOrbitalPeriod,
			testDistanceToStar, testMaxTemperature, testMinTemperature, testAtmosphere,
			testAtmosphereComposition, testGravity, testMagneticField, testLifeChance,
			testMoonsNum, testMoons, testId, testBelt, new AsteroidCluster("Test Planet's Belt", "Test Planet", 25000, { "D-type" }), testType) {}
	};
}

using namespace TPlanet;


TEST_CASE("Planet Abstract new Instance", TEST_NAME) {
	printStartTest(TEST_NAME);

	PlanetAbstract* testPlanet = new TestPlanet();
	AsteroidCluster* testCluster = new AsteroidCluster("Test Planet's Belt", "Test Planet", 25000, { "D-type" });
	THEN("Comparing") {
		REQUIRE(testPlanet->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
		REQUIRE(testPlanet->_name == testName);
		REQUIRE(testPlanet->_id == testId);
		REQUIRE(testPlanet->asteroidBelt->name == testCluster->name);
		REQUIRE(testPlanet->asteroidBelt->whoseOrbitOn == testCluster->whoseOrbitOn);
	}

	delete testPlanet;
	delete testCluster;
}

TEST_CASE("Methods default value", TEST_NAME) {
	printStartTest(TEST_NAME);

	PlanetAbstract* testPlanet = new TestPlanet();

	SECTION("getMoonsNum should be 4") {
		REQUIRE(testPlanet->getMoonsNum() == testMoonsNum);
	}

	SECTION("getUnexploredMoons should be return Full Vector of initial moons") {
		REQUIRE(testPlanet->getUnexploredMoons() == testMoons);
	}

	SECTION("getExploredMoons should be Empty") {
		REQUIRE(testPlanet->getExploredMoons().empty());
	}

	SECTION("getDistanceToStar should be 19.22f") {
		REQUIRE(testPlanet->getDistanceToStar() == testDistanceToStar);
	}

	delete testPlanet;
}

SCENARIO("makeMoonExplored method test", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creating Test Planet") {
		PlanetAbstract* testPlanet = new TestPlanet();

		GIVEN("Moon to make explored") {
			int testMoonId = 2;
			std::string testMoon = testMoons[2];

			std::vector<std::string> testExploredMoons = {
				"TestMoon_3"
			};

			std::vector<std::string> testUnexploredMoons = {
				"TestMoon_1", "TestMoon_2", "TestMoon_4"
			};

			WHEN("makeMoonExplored is called") {
				std::string testMoonOutput = testPlanet->makeMoonExplored(testMoonId);
				THEN("Every method should return correct value") {
					REQUIRE(testMoonOutput == testMoon);
					REQUIRE(testPlanet->getMoonsNum() == testMoonsNum);
					REQUIRE(testPlanet->getUnexploredMoons() == testUnexploredMoons);
					REQUIRE(testPlanet->getExploredMoons() == testExploredMoons);
				}
			}
		}

		delete testPlanet;
	}
}


TEST_CASE("Comparing Test Planet properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Test Planet generated") {
			PlanetAbstract* testPlanet = new TestPlanet();
			GIVEN("Expected output string") {
				std::string expectedOutput = "";

				expectedOutput += testName + " Planet Properties:";
				expectedOutput += "\n   Planet Type: " + testType;
				expectedOutput += "\n   Mass (KG): " + std::to_string(testMass) + " KG";
				expectedOutput += "\n   Radius (KM): " + std::to_string(testRadius) + " KM";
				expectedOutput += "\n   Day Duration (MIN): " + std::to_string(testDayDuration) + " hours";
				expectedOutput += "\n   Area (KM): " + std::to_string(testArea) + " KM^2";
				expectedOutput += "\n   Orbital Period (EarthDay): " + std::to_string(testOrbitalPeriod) + " Earth's Day";
				expectedOutput += "\n   Distance to Star (AU): " + std::to_string(testDistanceToStar) + " AU";
				expectedOutput += "\n   Max Surface Temperature (K): " + std::to_string(testMaxTemperature) + " K";
				expectedOutput += "\n   Min Surface Temperature (K): " + std::to_string(testMinTemperature) + " K";
				expectedOutput += "\n   Atmosphere (BOOL): ";
				expectedOutput += (testAtmosphere ? "True" : "False");
				if (testAtmosphere)
					expectedOutput += "\n   Atmosphere Composition ( {Element: Content%} ): ";
				for (auto it = testAtmosphereComposition.begin(); it != testAtmosphereComposition.end(); ++it) {
					expectedOutput += "\n   Element: " + it->first + " | Contains: " + std::to_string(it->second) + "%";
				}
				expectedOutput += "\n   Gravity (EarthG): " + std::to_string(testGravity) + " G";
				expectedOutput += "\n   Magnetic Field Strength (nT): " + std::to_string(testMagneticField) + " nT";
				expectedOutput += "\n   Life Chance (%): " + std::to_string(testLifeChance) + "%";
				expectedOutput += "\n   Moons Number: " + std::to_string(testMoonsNum) + "\n";

				THEN("showPlanetInfo called and compared") {
					std::stringstream output;

					std::streambuf* oldCout = std::cout.rdbuf();
					std::cout.rdbuf(output.rdbuf());

					testPlanet->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete testPlanet;
		}
	}
}
