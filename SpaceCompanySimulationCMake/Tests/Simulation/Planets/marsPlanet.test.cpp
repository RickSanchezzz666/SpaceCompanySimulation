#include <catch2/catch_all.hpp>

#define TEST_NAME "[MarsPlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/MarsPlanet.hpp"

namespace Mars {
	std::string testName = "Mars"; 
	long double testMass = 6.417E23L;
	float testRadius = 3389.5f;
	float testDayDuration = 1.025f;
	long double testArea = 144'800'000;
	float testOrbitalPeriod = 687.0f;
	float testDistanceToStar = 1.52f;
	int testMaxTemperature = 35;
	int testMinTemperature = -143;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = {
		{"Carbon Dioxide (CO2)", 95.32},
		{"Nitrogen (N)", 2.7},
		{"Argon (Ar)", 1.6},
		{"Oxygen (O2)", 0.13}
	};
	float testGravity = 0.377f;
	int testMagneticFieldStrength = 0;
	float testLifeChance = 0.005f;
	int testMoonsNum = 2;
	std::vector<std::string> testMoons = {
		"Phobos", "Deimos"
	};
	int testId = 3;
	bool testBelt = false;
	std::string testType = "Rocky";
}

using namespace Mars;


TEST_CASE("Create Mars", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Mars generated") {
			PlanetAbstract* mars = new MarsPlanet();

			THEN("Comparing") {
				REQUIRE(mars->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(mars->_name == testName);
				REQUIRE(mars->_id == testId);
			}

			delete mars;
		}
	}
}


TEST_CASE("Comparing Mars properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Mars generated") {
			PlanetAbstract* mars = new MarsPlanet();
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

					mars->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete mars;
		}
	}
}

