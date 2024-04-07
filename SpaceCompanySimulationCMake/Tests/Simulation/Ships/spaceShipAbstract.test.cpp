#include <catch2/catch_all.hpp>

#define TEST_NAME "[SpaceShipAbstract]"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

#include "../../TestRunner.hpp"

#include "../../../../Simulation/Models/SolarSystem/Ships/SpaceShipAbstract.hpp"

namespace TestShip {
	SpaceShipStatus testShipInitialStatus = SpaceShipStatus::ON_STATION;
	const SpaceShipType testShipType = SpaceShipType::TYPE_COUNT;
	const int testShipReqAstroNum = 10;

	class TShip : public SpaceShipAbstract {
	private:
		void __sendShipToObject(SolarSystem* sol, PlanetAbstract* planet) override {};
		void __sendShipToObject(SolarSystem* sol, StarsAbstract* sun) override {};
		void __sendShipToEarth(SolarSystem* sol, PlanetAbstract* planet) override {};
		void __sendShipToEarth(SolarSystem* sol, StarsAbstract* sun) override {};
		void __landShipOnStation() override {};

		int __calculateRevenue() override { return 0; };

	public:
		void increaseAstronautsNumber(std::atomic<short>& astroNum, const int num) {
			__increaseAstronautsNumber(astroNum, num);
		}

		void decreaseAstronautsNumber(std::atomic<short>& astroNum, const int num) {
			__decreaseAstronautsNumber(astroNum, num);
		}

		PlanetAbstract* getRandomPlanet(SolarSystem* sol) const {
			return __getRandomPlanet(sol);
		}

		AsteroidCluster* getRandomCluster(SolarSystem* sol) const {
			return __getRandomCluster(sol);
		}

		PlanetAbstract* getPlanet(SolarSystem* sol, int index) const { return __getPlanet(sol, index); }

		AsteroidCluster* getCluster(PlanetAbstract* planet) const { return __getCluster(planet); }

		PlanetAbstract* getPlanetByName(SolarSystem* sol, std::string& planetName) {
			return __getPlanetByName(sol, planetName);
		}

		int getTimeForFlight(SolarSystem* sol, std::string object) {
			return __getTimeForFlight(sol, object);
		}

		int calculateTimeForFlight(SolarSystem* sol, std::string oldObject, std::string newObject) {
			return __calculateTimeForFlight(sol, oldObject, newObject);
		}

		void __startEngine() override {
			for (int i = 3; i >= 0; --i) {
				printMessage(shipSign + " is launching in: " + std::to_string(i) + "\n");
			}
			printMessage(shipSign + " started engine...\n");
		};

		void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }

		void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

		std::string shipSign = " >Test Ship (id: " + std::to_string(this->shipId) + ")";

		TShip(int id) : SpaceShipAbstract(testShipInitialStatus, testShipType, testShipReqAstroNum, id) {}

		int launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override { return 0; };
	};

	std::string getCurrentTimestamp() {
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);
		std::tm timeinfo;
		localtime_s(&timeinfo, &time);

		std::ostringstream oss;
		oss << "[" << std::put_time(&timeinfo, "%H:%M:%S") << "]";
		return oss.str();
	}
}

using namespace TestShip;

SCENARIO("Create Ship Instance from Abstract", TEST_NAME) {
	printStartTest(TEST_NAME);
	SECTION("Creation of instances") {
		int id = 0;
		SpaceShipAbstract* testShip = new TShip(id);

		SECTION("Comparing default values") {
			GIVEN("Default values to compare") {
				ShipCurrentStatus currStatus = ShipCurrentStatus::LANDED;
				THEN("Values should be equal") {
					REQUIRE(testShip->shipId == id);
					REQUIRE(testShip->currentStatus == currStatus);
					REQUIRE(testShip->spaceShipStatus == testShipInitialStatus);
					REQUIRE(testShip->requiredAstronautsNumber == testShipReqAstroNum);
					REQUIRE(testShip->spaceShipType == testShipType);
				}
			}
		}

		SECTION("Testing methods") {
			WHEN("changeShipStatus is called") {
				testShip->changeShipStatus(ShipCurrentStatus::STARTING);
				THEN("currentStatus should change") {
					REQUIRE(testShip->currentStatus == ShipCurrentStatus::STARTING);
				}
			}
			AND_WHEN("printMessage w/o endl is called") {
				std::stringstream output;
				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());
				testShip->printMessage("Test Message1");
				std::string testMessageNoEndl = getCurrentTimestamp() + "Test Message1";

				THEN("printMessage w/o endl") {
					REQUIRE(output.str() == testMessageNoEndl);
				}
				std::cout.rdbuf(oldCout);
			}
			AND_WHEN("printMessage with endl is called") {
				std::stringstream output;
				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());
				testShip->printMessage("Test Message2", true);
				std::string testMessageEndl = "\n" + getCurrentTimestamp() + "Test Message2";

				THEN("printMessage with endl") {
					REQUIRE(output.str() == testMessageEndl);
				}
				std::cout.rdbuf(oldCout);
			}
		}

		delete testShip;
	}
}

SCENARIO("Create Ship Instance from Test Class", TEST_NAME) {
	printStartTest(TEST_NAME);

	SECTION("Creation of instances") {
		int id = 0;
		TShip* testShip = new TShip(id);
		SolarSystem* sol = new SolarSystem();
		std::string shipSign = " >Test Ship (id: " + std::to_string(id) + ")";

		GIVEN("Default value to shipSign") {
			THEN("Values should be equal") {
				REQUIRE(testShip->shipSign == shipSign);
			}
		}

		SECTION("Testing methods") {
			WHEN("__setSpaceShipsStatus is called") {
				testShip->__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
				THEN("spaceShipStatus should change") {
					REQUIRE(testShip->spaceShipStatus == SpaceShipStatus::AVAILABLE);
				}
			}
			AND_WHEN("__stopEngine is called") {
				std::stringstream output;
				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());
				testShip->__stopEngine();
				std::string expectedOutput = getCurrentTimestamp() + shipSign + " stopped engine...\n";

				THEN("__stopEngine should be equal to expected") {
					REQUIRE(output.str() == expectedOutput);
				}
				std::cout.rdbuf(oldCout);
			}
			AND_WHEN("__startEngine is called") {
				std::stringstream output;
				std::streambuf* oldCout = std::cout.rdbuf();
				std::cout.rdbuf(output.rdbuf());
				testShip->__startEngine();
				std::string expectedOutput = "";
				for (int i = 3; i >= 0; --i) {
					expectedOutput += getCurrentTimestamp() + shipSign + " is launching in: " + std::to_string(i) + "\n";
				}
				expectedOutput += getCurrentTimestamp() + shipSign + " started engine...\n";

				THEN("__startEngine should be equal to expected") {
					REQUIRE(output.str() == expectedOutput);
				}
				std::cout.rdbuf(oldCout);
			}
			GIVEN("astronautsCounter") {
				std::atomic<short> astronautsNumOnTheStation = 26;
				WHEN("increaseAstronautsNumber is called") {
					testShip->increaseAstronautsNumber(astronautsNumOnTheStation, 10);
					THEN("astronautsNumber should change") {
						REQUIRE(astronautsNumOnTheStation.load() == 26 + 10);
					}
				}
				AND_WHEN("decreaseAstronautsNumber is called") {
					testShip->decreaseAstronautsNumber(astronautsNumOnTheStation, 5);
					THEN("astronautsNumber should change") {
						REQUIRE(astronautsNumOnTheStation.load() == 26 - 5);
					}
				}
			}
			AND_WHEN("getRandomPlanet is called") {
				PlanetAbstract* planet = testShip->getRandomPlanet(sol);
				THEN("randomPlanetId should be in range from 1 to 7") {
					REQUIRE((planet->_id >= 1 && planet->_id <= 7));
				}
			}
			AND_WHEN("getRandomCluster is called") {
				AsteroidCluster* cluster = testShip->getRandomCluster(sol);
				THEN("cluster should be on Sun's orbit") {
					REQUIRE(cluster->whoseOrbitOn == "Sun");
				}
			}
			AND_WHEN("getPlanet and getPlanetByName is called") {
				GIVEN("Planet index that should be in range of 0 - 6 and planetName") {
					std::string planetName = "Venus";

					PlanetAbstract* planetByName = testShip->getPlanetByName(sol, planetName);

					int index = planetByName->_id - 1;
					REQUIRE((index >= 0 && index <= 6));

					PlanetAbstract* planetByIndex = planetByIndex = testShip->getPlanet(sol, index);

					THEN("Planets should be equal") {
						REQUIRE(planetByName->_name == planetByIndex->_name);
						REQUIRE(planetByName->_id == planetByIndex->_id);
						REQUIRE(planetByName->timeFromEarthToPlanet == planetByIndex->timeFromEarthToPlanet);
					}
				}
			}
			AND_WHEN("getCluster is called") {
				std::string planetName = "Jupiter";

				PlanetAbstract* planetByName = testShip->getPlanetByName(sol, planetName);

				AsteroidCluster* cluster = testShip->getCluster(planetByName);
				THEN("cluster should be on Jupiter's orbit") {
					REQUIRE(cluster->whoseOrbitOn == "Jupiter");
					REQUIRE(cluster->name == "Jupiter's Belt");
				}
			}
			AND_WHEN("getTimeForFlight is called") {
				std::string planetName = "Jupiter";

				PlanetAbstract* planetByName = testShip->getPlanetByName(sol, planetName);

				int time = testShip->getTimeForFlight(sol, planetName);
				THEN("time should be equal to time from Earth") {
					REQUIRE(time == planetByName->timeFromEarthToPlanet);
				}
			}

			AND_WHEN("calculateTimeForFlight is called") {
				std::string planetNameOld = "Jupiter";
				std::string planetNameNew = "Neptune";

				PlanetAbstract* planetByNameOld = testShip->getPlanetByName(sol, planetNameOld);
				PlanetAbstract* planetByNameNew = testShip->getPlanetByName(sol, planetNameNew);

				float distanceOld = (planetNameOld != "Sun" ? testShip->getPlanetByName(sol, planetNameOld)->getDistanceToStar() : 0.0f);
				float distanceNew = (planetNameNew != "Sun" ? testShip->getPlanetByName(sol, planetNameNew)->getDistanceToStar() : 0.0f);
				int expectedTime = static_cast<int>(abs((distanceOld - distanceNew) * 15));

				int time = testShip->calculateTimeForFlight(sol, planetNameOld, planetNameNew);
				THEN("expected time should be equal to calculated") {
					REQUIRE(time == expectedTime);
				}
			}
		}

		delete testShip;
		delete sol;
	}
}