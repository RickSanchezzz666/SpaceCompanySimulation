#include <catch2/catch_all.hpp>

#define TEST_NAME "[UranusPlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/UranusPlanet.hpp"

namespace Uranus {
	std::string testName = "Uranus";
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
	int testMoonsNum = 27;
	std::vector<std::string> testMoons = {
		"Miranda", "Ariel", "Umbriel", "Titania", "Oberon", "Cordelia", "Ophelia",
		"Bianca", "Cressida", "Desdemona", "Juliet", "Portia", "Rosalind", "Belinda", "Puck",
		"Caliban", "Sycorax", "Prospero", "Setebos", "Stephano", "Trinculo", "Francisco",
		"Margaret", "Ferdinand", "Perdita"
	};
	int testId = 6;
	bool testBelt = true;
	std::string testType = "Class I gas giant";
}

using namespace Uranus;


TEST_CASE("Create Uranus", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Uranus generated") {
			PlanetAbstract* uranus = new UranusPlanet();
			AsteroidCluster* testCluster = new AsteroidCluster("Uranus's Belt", "Uranus", 2500, { "C-type" });

			THEN("Comparing") {
				REQUIRE(uranus->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(uranus->_name == testName);
				REQUIRE(uranus->_id == testId);
				REQUIRE(uranus->asteroidBelt->name == testCluster->name);
				REQUIRE(uranus->asteroidBelt->whoseOrbitOn == testCluster->whoseOrbitOn);
			}

			delete uranus;
			delete testCluster;
		}
	}
}


TEST_CASE("Comparing Uranus properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Uranus generated") {
			PlanetAbstract* uranus = new UranusPlanet();
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

					uranus->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete uranus;
		}
	}
}

