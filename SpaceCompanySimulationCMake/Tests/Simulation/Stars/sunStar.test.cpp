#include <catch2/catch_all.hpp>

#define TEST_NAME "[SunStar]"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Stars/SunStar.hpp"

namespace Sun {
	long double testMass = 1.9885E30L;
	float testRadius = 696'000;
	long double testArea = 6.09E12L;
	float testAge = 4.6f;
	int testTemp = 5772;
	std::string testStarType = "G (White Yellow)";
	std::string testLuminosity = "V";
	std::string testSpectralClass = "G2 V";
	float testAbsoluteMagnitude = 4.83f;
	int testDistance = 26660;
	std::string testName = "Sun";
	int testTime = 15;
	int testId = 0;
}

using namespace Sun;

TEST_CASE("Create Sun", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation and comparing") {
		GIVEN("Sun generated") {
			StarsAbstract* sun = new SunStar();

			THEN("Comparing") {
				REQUIRE(sun->timeFromEarthToStar == testTime);
				REQUIRE(sun->name == testName);
				REQUIRE(sun->_id == testId);
			}
			delete sun;
		}
	}
}

TEST_CASE("Comparing properties to showStarInfo method") {
	printStartTest(TEST_NAME);

	SECTION("Properties comparing") {
		GIVEN("Sun generated") {
			StarsAbstract* sun = new SunStar();
			GIVEN("Expected output string") {
				std::string expectedOutput = "";

				expectedOutput += "Sun Star Properties:";
				expectedOutput += "\n   Mass (KG): " + std::to_string(testMass) + " KG";
				expectedOutput += "\n   Radius (KM): " + std::to_string(testRadius) + " KM";
				expectedOutput += "\n   Area (KM): " + std::to_string(testArea) + " KM^2";
				expectedOutput += "\n   Age (Billion Years): " + std::to_string(testAge) + "B Years";
				expectedOutput += "\n   Surface Temperature (K): " + std::to_string(testTemp) + " K";
				expectedOutput += "\n   Star's Type: " + testStarType;
				expectedOutput += "\n   Star's Luminosity: " + testLuminosity;
				expectedOutput += "\n   Star's Full Spectral Class: " + testSpectralClass;
				expectedOutput += "\n   Absolute Magnitued: " + std::to_string(testAbsoluteMagnitude);
				expectedOutput += "\n   Distance to the Center of the Galaxy (LY): " + std::to_string(testDistance) + " Light Years\n";

				THEN("showStarInfo called and compared") {
					std::stringstream output;

					std::streambuf* oldCout = std::cout.rdbuf();
					std::cout.rdbuf(output.rdbuf());

					sun->showStarInfo();

					std::cout.rdbuf(oldCout);

					REQUIRE(output.str() == expectedOutput);
				}
			}
			delete sun;
		}
	}
}

