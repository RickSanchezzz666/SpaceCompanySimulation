#include <catch2/catch_all.hpp>

#define TEST_NAME "[VenusPlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/VenusPlanet.hpp"

namespace Venus {
	std::string testName = "Venus";
	long double testMass = 4.867E24L;
	float testRadius = 6051.8f;
	float testDayDuration = 243.025f;
	long double testArea = 460'200'000;
	float testOrbitalPeriod = 224.7f;
	float testDistanceToStar = 0.72f;
	int testMaxTemperature = 464;
	int testMinTemperature = 462;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = { {"Carbon Dioxide (CO2)", 96.5}, {"Nitrogen (N)", 3.5} };
	float testGravity = 0.907f;
	int testMagneticField = 0;
	float testLifeChance = .0f;
	int testMoonsNum = 0;
	std::vector<std::string> testMoons = {};
	int testId = 2;
	bool testBelt = false;
	std::string testType = "High metal content world";
}

using namespace Venus;


TEST_CASE("Create Venus", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Venus generated") {
			PlanetAbstract* venus = new VenusPlanet();

			THEN("Comparing") {
				REQUIRE(venus->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(venus->_name == testName);
				REQUIRE(venus->_id == testId);
			}

			delete venus;
		}
	}
}


TEST_CASE("Comparing Venus properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Venus generated") {
			PlanetAbstract* venus = new VenusPlanet();
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

					venus->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete venus;
		}
	}
}

