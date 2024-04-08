#include <catch2/catch_all.hpp>

#define TEST_NAME "[EarthStation]"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../TestRunner.hpp"

#include "../../../Simulation/Features/EarthStation.hpp"

TEST_CASE("Creating instance of EarthStation", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creating instances") {
		GIVEN("SolarSystem instance") {
			SolarSystem* sol = new SolarSystem();
			WHEN("Creating EarthStation instance") {
				EarthStation* earthStation = new EarthStation(sol);
				THEN("Also Balance instance should be created") {
					REQUIRE(earthStation->balance != nullptr);
				}
				AND_THEN("SolarSystem pointer also should be created") {
					REQUIRE(earthStation->solarSystem != nullptr);
				}
				delete earthStation;
			}
			delete sol;
		}
	}
}

SCENARIO("Testing methods of Earth Station") {
	printStartTest(TEST_NAME);

	GIVEN("Created instance of Earth Station") {
		SolarSystem* sol = new SolarSystem();
		EarthStation* earthStation = new EarthStation(sol);
		SECTION("Default values of methods") {
			WHEN("checkIfShipIsAvailable is called") {
				// 0 id - explorer ship
				bool availableExplorer = earthStation->checkIfShipIsAvailable(0);
				// 2 id - mining ship
				bool availableMining = earthStation->checkIfShipIsAvailable(2);
				THEN("Should return TRUE for 0 and FALSE for 2") {
					REQUIRE(availableExplorer);
					REQUIRE(!availableMining);
				}
			}
			AND_WHEN("checkIfShipIsAvailable is called") {
				int astronautsNumber = earthStation->getAstronautsNumber();
				THEN("Should return 26 for default") {
					REQUIRE(astronautsNumber == 26);
				}
			}
			AND_WHEN("showAstronautsNumber is called") {
				std::string expectedOutput = "\nAstronauts currently on Station: " + std::to_string(earthStation->getAstronautsNumber());

				std::stringstream output;

				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());

				earthStation->showAstronautsNumber();

				THEN("Output should be equal to expected") {
					REQUIRE(output.str() == expectedOutput);
				}
				std::cout.rdbuf(oldCout);
			}
			AND_WHEN("getShipsNumber is called") {
				int shipNumber = earthStation->getShipsNumber();
				THEN("Should return 6 for default") {
					REQUIRE(shipNumber == 6);
				}
			}
			AND_WHEN("getBusyShipsNumber is called") {
				int busyShipNumber = earthStation->getBusyShipsNumber();
				THEN("Should return 0 for default") {
					REQUIRE(busyShipNumber == 0);
				}
			}
			AND_WHEN("displayAvailableSpaceShips is called") {
				std::string expectedOutput = "\nAvailable ships: \nShip Id: 0; Ship Type: Explorer\nShip Id: 1; Ship Type: Explorer\nShip Id: 4; Ship Type: Passenger\nShip Id: 5; Ship Type: Passenger\n";

				std::stringstream output;

				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());

				earthStation->displayAvailableSpaceShips();

				THEN("Output should be equal to expected") {
					REQUIRE(output.str() == expectedOutput);
				}
				std::cout.rdbuf(oldCout);
			}
			AND_WHEN("displayEveryShip is called") {
				std::string expectedOutput = "\nEvery Ship that Station own: \nShip Id: 0; Ship Type: Explorer\nShip Id: 1; Ship Type: Explorer\nShip Id: 2; Ship Type: Mining\nShip Id: 3; Ship Type: Mining\nShip Id: 4; Ship Type: Passenger\nShip Id: 5; Ship Type: Passenger\n";

				std::stringstream output;

				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());

				earthStation->displayEveryShip();

				THEN("Output should be equal to expected") {
					REQUIRE(output.str() == expectedOutput);
				}
				std::cout.rdbuf(oldCout);
			}
		}
		delete earthStation;
		delete sol;
	}
}