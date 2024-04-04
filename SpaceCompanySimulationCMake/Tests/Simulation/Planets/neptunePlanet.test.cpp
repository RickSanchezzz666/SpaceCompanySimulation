#include <catch2/catch_all.hpp>

#define TEST_NAME "[NeptunePlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/NeptunePlanet.hpp"

namespace Neptune {
	std::string testName = "Neptune";
	long double testMass = 1.02413E26L;
	float testRadius = 24622.0f;
	float testDayDuration = 16.11f;
	long double testArea = 7.618E9L;
	float testOrbitalPeriod = 60190.0f;
	float testDistanceToStar = 30.05f;
	int testMaxTemperature = 72;
	int testMinTemperature = 46;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = {
		{"Hydrogen (H2)", 80},
		{"Methane (CH4)", 1.5},
		{"Helium (He)", 19}
	};
	float testGravity = 1.14f;
	int testMagneticFieldStrength = 7200;
	float testLifeChance = 0.001f;
	int testMoonsNum = 14;
	std::vector<std::string> testMoons = { "Triton", "Nereid", "Naiad", "Thalassa", "Despina", "Galatea", "Larissa", "Proteus",
											"Halimede", "Psamathe", "Sao", "Laomedeia", "Neso" };
	int testId = 7;
	bool testBelt = true;
	std::string testType = "Class I gas giant";
}

using namespace Neptune;


TEST_CASE("Create Neptune", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Neptune generated") {
			PlanetAbstract* neptune = new NeptunePlanet();
			AsteroidCluster* testCluster = new AsteroidCluster("Neptune's Belt", "Neptune", 39'000, { "C-type" });

			THEN("Comparing") {
				REQUIRE(neptune->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(neptune->_name == testName);
				REQUIRE(neptune->_id == testId);
				REQUIRE(neptune->asteroidBelt->name == testCluster->name);
				REQUIRE(neptune->asteroidBelt->whoseOrbitOn == testCluster->whoseOrbitOn);
			}

			delete neptune;
			delete testCluster;
		}
	}
}


TEST_CASE("Comparing Neptune properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Neptune generated") {
			PlanetAbstract* neptune = new NeptunePlanet();
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
				expectedOutput += "\n   Magnetic Field Strength (nT): " + std::to_string(testMagneticFieldStrength) + " nT";
				expectedOutput += "\n   Life Chance (%): " + std::to_string(testLifeChance) + "%";
				expectedOutput += "\n   Moons Number: " + std::to_string(testMoonsNum) + "\n";

				THEN("showPlanetInfo called and compared") {
					std::stringstream output;

					std::streambuf* oldCout = std::cout.rdbuf();
					std::cout.rdbuf(output.rdbuf());

					neptune->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete neptune;
		}
	}
}

