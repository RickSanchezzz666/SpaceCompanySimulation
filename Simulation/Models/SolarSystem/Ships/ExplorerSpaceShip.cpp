#include "ExplorerSpaceShip.hpp"

void ExplorerSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		printMessage(shipSign + " is launching in: " + std::to_string(i) + "\n");
		threadSleep(1);
	}
	printMessage(shipSign + " started engine...\n");
}

void ExplorerSpaceShip::__sendShipToObject(PlanetAbstract* planet) {
	threadSleep(2);
	printMessage(shipSign + " route is set with the goal of exploring " + planet->_name + "..\n");
	threadSleep(5);
	if (__objectsSearched.empty()) {
		printMessage(shipSign + " left Earth's atmosphere..\n");
		threadSleep(2);
	}
	printMessage(shipSign + " is currently heading to " + planet->_name + "..\n");
	threadSleep(planet->timeFromEarthToPlanet);
	printMessage(shipSign + " reached " + planet->_name + "'s orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " is currently orbiting " + planet->_name + "..\n");
}

void ExplorerSpaceShip::__sendShipToObject(StarsAbstract* sun) {
	threadSleep(2);
	printMessage(shipSign + " route is set with the goal of exploring " + sun->name + "..\n");
	threadSleep(5);
	if (__objectsSearched.empty()) {
		printMessage(shipSign + " left Earth's atmosphere..\n");
		threadSleep(2);
	}
	printMessage(shipSign + " is currently heading to " + sun->name + "..\n");
	threadSleep(sun->timeFromEarthToStar);
	printMessage(shipSign + " reached " + sun->name + "'s orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " is currently orbiting " + sun->name + "..\n");
}

void ExplorerSpaceShip::__sendShipToEarth(PlanetAbstract* planet) {
	threadSleep(5);
	printMessage(shipSign + " started heading back to Earth from exploration..\n");
	threadSleep(planet->timeFromEarthToPlanet);
	printMessage(shipSign + " is on Earth's orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " began to enter Earth's atmosphere..\n");
}

void ExplorerSpaceShip::__sendShipToEarth(StarsAbstract* star) {
	threadSleep(5);
	printMessage(shipSign + " started heading back to Earth from exploration..\n");
	threadSleep(star->timeFromEarthToStar);
	printMessage(shipSign + " is on Earth's orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " began to enter Earth's atmosphere..\n");
}

void ExplorerSpaceShip::__landShipOnStation() {
	threadSleep(2);
	printMessage(shipSign + " is getting ready to land on Earth's Station..\n");
	threadSleep(3);
	printMessage(shipSign + " successfully landed on Earth's Station..\n");
	this->__stopEngine();
}

void ExplorerSpaceShip::__continueExploration(SolarSystem* sol, std::string objName) {
	bool againSwitch = static_cast<bool>(Random::getRandomNumber(0, 1));
	if (againSwitch) {
		printMessage(shipSign + " getting ready to come back to Earth..\n");
		threadSleep(2);
	}
	else {
		int targetObject = Random::getRandomNumber(0, sol->planets.size());
		if (targetObject == 0) {
			bool foundStatus = false;
			for (auto& id : __objectsSearched) {
				if (targetObject == id) {
					threadSleep(1);
					printMessage(shipSign + " crew is tired. Getting ready to come back to Earth..\n");
					foundStatus = true;
					return;
				}
			}
			if (!foundStatus) {
				printMessage(shipSign + " looking for another Planet or Star to explore..\n");
				threadSleep(2);
				__objectsSearched.push_back(sol->star->_id);
				__sendShipToObject(sol->star);
				__doExploration(sol, sol->star);
			}
		}
		else {
			bool foundStatus = false;
			for (auto& id : __objectsSearched) {
				if (targetObject == id) {
					threadSleep(1);
					printMessage(shipSign + " crew is tired. Getting ready to come back to Earth..\n");
					foundStatus = true;
					return;
				}
			}
			if (!foundStatus) {
				printMessage(shipSign + " looking for another Planet or Star to explore..\n");
				threadSleep(2);
				PlanetAbstract* newPlanet = __getPlanet(sol, targetObject - 1);
				__objectsSearched.push_back(newPlanet->_id);
				__sendShipToObject(newPlanet);
				__doExploration(sol, newPlanet);
			}
		}
	}
}

void ExplorerSpaceShip::__doExploration(SolarSystem* sol, StarsAbstract* sun) {
	threadSleep(2);
	printMessage(shipSign + " exploring star...");
	threadSleep(2);
	//__objectsSearched++;
	//int targetObject = Random::getRandomNumber(1, sol->planets.size());// except Sun
	//__sendShipToEarth(sun);
}

void ExplorerSpaceShip::__doExploration(SolarSystem* sol, PlanetAbstract* planet) {
	threadSleep(2);
	__expeditionNum++;
	printMessage(shipSign + " is scanning for potential interesting objects..\n");
	threadSleep(1);
	printMessage(shipSign + " EXPLORER'S RADIO: Scanning...\n");
	threadSleep(5);
	if (planet->getMoonsNum() == 0 || planet->getUnexploredMoons().size() == 0) {
		printMessage(shipSign + " EXPLORER'S RADIO: None of interesting objects were found..\n");
		threadSleep(2);
		__continueExploration(sol, planet->_name);
	}
	else {
		do {
			if (planet->getUnexploredMoons().size() == 0) {
				printMessage(shipSign + " EXPLORER'S RADIO: All moons were discovered!.\n");
				threadSleep(2);
				break;
			}
			std::string foundMoon = planet->makeMoonExplored(Random::getRandomNumber(0, planet->getUnexploredMoons().size() - 1));
			_exploredData.push_back(foundMoon);
			printMessage(shipSign + " EXPLORER'S RADIO: New Moon was found: " + foundMoon + "!.\n");
			threadSleep(2);
		} while (static_cast<bool>(Random::getRandomNumber(0, 1)));

		__continueExploration(sol, planet->_name);
	}

	if (__expeditionNum == 1) {
		threadSleep(2);
		__sendShipToEarth(planet);
	}
	else {
		__expeditionNum--;
	}
}

void ExplorerSpaceShip::__concludeExploration() {
	threadSleep(2);
	std::cout << "\nResults of expedition of Explorer Ship(id: " + std::to_string(this->shipId) + ") :\n";
	std::cout << "Found objects: ";
	if (_exploredData.size() == 0) printMessage("None!.\n");
	else {
		for (std::string& obj : _exploredData) {
			std::cout << "\nObject: " + obj;
		}
		std::cout << "\n";
	}
}


void ExplorerSpaceShip::launchShip(std::atomic<short>& astroNum, SolarSystem* sol) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	printMessage(shipSign + " is preparing for a flight..\n", true);
	printMessage(shipSign + " is launching..\n");
	this->__startEngine();
	int targetObject = Random::getRandomNumber(1, sol->planets.size());
	//0 - Sun
	//other - Planets
	if (targetObject == 0) {
		__sendShipToObject(sol->star);
		__objectsSearched.push_back(sol->star->_id);
		__doExploration(sol, sol->star);
	}
	else {
		PlanetAbstract* planet = __getRandomPlanet(sol);
		__sendShipToObject(planet);
		__objectsSearched.push_back(planet->_id);
		__doExploration(sol, planet);
	}
	__landShipOnStation();
	__concludeExploration();
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__objectsSearched.clear();
	__expeditionNum = 0;
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
