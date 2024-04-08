#include <catch2/catch_all.hpp>

#define TEST_NAME "[MercuryPlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/MercuryPlanet.hpp"

namespace Mercury {
	std::string testName = "Mercury";
	long double testMass = 3E23L;
	float testRadius = 2439.7f;
	float testDayDuration = 59.f;
	long double testArea = 74'800'000;
	float testOrbitalPeriod = 87.969f;
	float testDistanceToStar = 0.4f;
	int testMaxTemperature = 700;
	int testMinTemperature = 90;
	bool testAtmosphere = false;
	std::unordered_map<std::string, float> testAtmosphereComposition;
	float testGravity = 0.378f;
	int testMagneticFieldStrength = 300;
	float testLifeChance = 0.00005f;
	int testMoonsNum = 0;
	std::vector<std::string> testMoons;
	int testId = 1;
	bool testBelt = false;
	std::string testType = "Metal-rich";
}

using namespace Mercury;


TEST_CASE("Create Mercury", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Mercury generated") {
			PlanetAbstract* mercury = new MercuryPlanet();

			THEN("Comparing") {
				REQUIRE(mercury->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(mercury->_name == testName);
				REQUIRE(mercury->_id == testId);
			}

			delete mercury;
		}
	}
}


TEST_CASE("Comparing Mercury properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Mercury generated") {
			PlanetAbstract* mercury = new MercuryPlanet();
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

					mercury->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete mercury;
		}
	}
}

