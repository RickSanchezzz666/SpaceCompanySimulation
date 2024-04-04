#include <catch2/catch_all.hpp>

#define TEST_NAME "[JupiterPlanet]"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Planets/JupiterPlanet.hpp"

namespace Jupiter {
	std::string testName = "Jupiter";
	long double testMass = 1.898E27L;
	float testRadius = 69911.0f;
	float testDayDuration = 9.925f;
	long double testArea = 6.142E10L;
	float testOrbitalPeriod = 4332.6f;
	float testDistanceToStar = 5.20f;
	int testMaxTemperature = 165;
	int testMinTemperature = 110;
	bool testAtmosphere = true;
	std::unordered_map<std::string, float> testAtmosphereComposition = {
		{"Hydrogen (H2)", 90}, {"Helium (He)", 10}
	};
	float testGravity = 2.528f;
	int testMagneticFieldStrength = 42000;
	float testLifeChance = 0.01f;
	int testMoonsNum = 72;
	std::vector<std::string> testMoons = {
		"Metis", "Adrastea", "Amalthea", "Thebe", "Io", "Europa", "Ganymede", "Callisto", "Themisto", "Leda",
		"Himalia", "Lysithea", "Elara", "Dia", "Carpo", "Valetudo", "Euporie", "Orthosie", "Euanthe", "Thyone",
		"Harpalyke", "Hermippe", "Praxidike", "Isonoe", "Mneme", "Helike", "Ananke", "Herse", "Aitne", "Kale",
		"Taygete", "Chaldene", "Eurynome", "Autonoe", "Sponde", "Pasithee", "Megaclite", "Sinope", "Callirrhoe",
		"Aoede", "Kalyke", "Kore", "Cyllene", "Eukelade", "Pasiphae", "Hegemone", "Arche", "Iocaste", "Erinome",
		"Harmony", "Eupheme", "Thelxinoe", "Eirene", "Philophrosyne"
	};
	int testId = 4;
	bool testBelt = true;
	std::string testType = "Class I gas giant";
}

using namespace Jupiter;


TEST_CASE("Create Jupiter", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Jupiter generated") {
			PlanetAbstract* jupiter = new JupiterPlanet();

			AsteroidCluster* testCluster = new AsteroidCluster("Jupiter's Belt", "Jupiter", 175'000, { "C-type", "D-type" });

			THEN("Comparing") {
				REQUIRE(jupiter->timeFromEarthToPlanet == static_cast<int>(abs(1 - testDistanceToStar) * 15));
				REQUIRE(jupiter->_name == testName);
				REQUIRE(jupiter->_id == testId);
				REQUIRE(jupiter->asteroidBelt->name == testCluster->name);
				REQUIRE(jupiter->asteroidBelt->whoseOrbitOn == testCluster->whoseOrbitOn);
			}

			delete jupiter;
			delete testCluster;
		}
	}
}


TEST_CASE("Comparing Jupiter properties to showPlanetInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Jupiter generated") {
			PlanetAbstract* jupiter = new JupiterPlanet();
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

					jupiter->showPlanetInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete jupiter;
		}
	}
}

