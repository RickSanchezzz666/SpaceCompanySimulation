#include <catch2/catch_all.hpp>

#define TEST_NAME "[SaturnPlanet]"

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/SaturnPlanet.hpp"

namespace Saturn {
	std::string testName = "Saturn";
	long double testMass = 5.6834E26L;
	float testRadius = 58232.0f;
	float testDayDuration = 10.656f;
	long double testArea = 4.27E10L;
	float testOrbitalPeriod = 10759.22f;
	float testDistanceToStar = 9.58f;
	int testMaxTemperature = 134;
	int testMinTemperature = 84;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = { {"Hydrogen (H2)", 96.3}, {"Helium (He)", 3.25} };
	float testGravity = 1.065f;
	int testMagneticField = 20000;
	float testLifeChance = 0.01f;
	int testMoonsNum = 82;
	std::vector<std::string> testMoons = {
		"Mimas", "Enceladus", "Tethys", "Dione", "Rhea", "Titan", "Hyperion", "Iapetus",
		"Phoebe", "Janus", "Epimetheus", "Helene", "Telesto", "Calypso", "Atlas",
		"Prometheus", "Pandora", "Pan", "Ymir", "Paaliaq", "Tarvos", "Ijiraq", "Suttungr",
		"Kiviuq", "Mundilfari", "Albiorix", "Skathi", "Siarnaq", "Thrymr", "Narvi",
		"Methone", "Pallene", "Daphnis", "Aegir", "Bebhionn", "Beli", "Bergelmir",
		"Bestla", "Farbauti", "Fenrir", "Fornjot", "Greip", "Hati", "Hyrrokkin",
		"Jarnsaxa", "Kari", "Loge", "Skoll", "Surtur", "Anthe", "Aegaeon"
	};
	int testId = 5;
	bool testBelt = true;
	std::string testType = "Class I gas giant";
}

using namespace Saturn;


TEST_CASE("Create Saturn", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Saturn generated") {
			PlanetAbstract* saturn = new SaturnPlanet();
			AsteroidCluster* testCluster = new AsteroidCluster("Saturn's Rings", "Saturn", 300'000, { "C-type", "D-type" });

			THEN("Comparing") {
				REQUIRE(saturn->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(saturn->_name == testName);
				REQUIRE(saturn->_id == testId);
				REQUIRE(saturn->asteroidBelt->name == testCluster->name);
				REQUIRE(saturn->asteroidBelt->whoseOrbitOn == testCluster->whoseOrbitOn);
			}

			delete saturn;
			delete testCluster;
		}
	}
}


TEST_CASE("Comparing Saturn properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Saturn generated") {
			PlanetAbstract* saturn = new SaturnPlanet();
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

					saturn->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete saturn;
		}
	}
}

