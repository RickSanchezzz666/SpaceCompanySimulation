#include "PassengerSpaceShip.hpp"

void PassengerSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		std::cout << shipSign + " is launching in: " + std::to_string(i) + "\n";
		threadSleep(1);
	}
	std::cout << shipSign + " started engine...\n";
}

void PassengerSpaceShip::__getPassengersOnBoard(const int passengersNum) { 
	__currPassengersAmount.fetch_add(passengersNum, std::memory_order_relaxed); 
	std::cout << shipSign + " boarded " + std::to_string(passengersNum) + " passengers..\n";
}

void PassengerSpaceShip::__removePassengersFromBoard() { 
	std::cout << shipSign + " " + std::to_string(__currPassengersAmount) + " passengers left a board..\n";
	__currPassengersAmount = 0;
}

void PassengerSpaceShip::__touristsAction(int tObject) {
	int randomNum = -1;
	if (tObject == 0) {
		randomNum = Random::getRandomNumber(0, 4);
	}
	else {
		randomNum = Random::getRandomNumber(5, 9);
	}
	threadSleep(2);
	switch (randomNum)
	{
	case 0:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Astronomical observations, photography, analysis..\n";
		break;
	case 1:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Studying space debris, its impact..\n";
		break;
	case 2:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Gravity field analysis, research..\n";
		break;
	case 3:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Leisure time, relaxation, meditation, stargazing..\n";
		break;
	case 4:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Astronavigation, star charts, orientation..\n";
		break;
	case 5:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Touring orbit, learning..\n";
		break;
	case 6:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Observing cosmic phenomena..\n";
		break;
	case 7:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Drone flights, mapping..\n";
		break;
	case 8:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Planetary surface reconnaissance, soil analysis..\n";
		break;
	case 9:
		std::cout << shipSign + " TOURIST'S RADIO: " + "Experiment preparation and execution training..\n";
		break;
	default:
		std::cout << shipSign + " TOURIST'S RADIO: " + "BAD CONNECTION...\n";
		break;
	}
}

void PassengerSpaceShip::__sendShipToObject(PlanetAbstract* planet) {
	threadSleep(2);
	std::cout << shipSign + " route is set with the goal of reaching " + planet->_name + "..\n";
	threadSleep(5);
	std::cout << shipSign + " left Earth's atmosphere..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently heading to " + planet->_name + "..\n";
	threadSleep(planet->timeFromEarthToPlanet);
	std::cout << shipSign + " reached " + planet->_name + "'s orbit..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently orbiting " + planet->_name + "..\n";
}

void PassengerSpaceShip::__sendShipToObject(StarsAbstract* sun) {
	threadSleep(2);
	std::cout << shipSign + " route is set with the goal of reaching " + sun->name + "..\n";
	threadSleep(5);
	std::cout << shipSign + " left Earth's atmosphere..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently heading to " + sun->name + "..\n";
	threadSleep(sun->timeFromEarthToStar);
	std::cout << shipSign + " reached " + sun->name + "'s orbit..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently orbiting " + sun->name + "..\n";
}

void PassengerSpaceShip::__sendShipToEarth(PlanetAbstract* planet) {
	threadSleep(5);
	std::cout << shipSign + " started heading back to Earth..\n";
	threadSleep(planet->timeFromEarthToPlanet);
	std::cout << shipSign + " is on Earth's orbit..\n";
	threadSleep(2);
	std::cout << shipSign + " began to enter Earth's atmosphere..\n";
}

void PassengerSpaceShip::__sendShipToEarth(StarsAbstract* star) {
	threadSleep(5);
	std::cout << shipSign + " started heading back to Earth..\n";
	threadSleep(star->timeFromEarthToStar);
	std::cout << shipSign + " is on Earth's orbit..\n";
	threadSleep(2);
	std::cout << shipSign + " began to enter Earth's atmosphere..\n";
}

void PassengerSpaceShip::__landShipOnStation() {
	threadSleep(2);
	std::cout << shipSign + " is getting ready to land on Earth's Station..\n";
	threadSleep(3);
	std::cout << shipSign + " successfully landed on Earth's Station..\n";
	this->__stopEngine();
}

void PassengerSpaceShip::launchShip(std::atomic<short>& astroNum, SolarSystem* sol) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	std::cout << "\n" + shipSign + " is preparing for a flight..\n";
	__getPassengersOnBoard(Random::getRandomNumber(10, 30));
	std::cout << shipSign + " is launching..\n";
	this->__startEngine();
	int targetObject = Random::getRandomNumber(0, sol->planets.size());
	//0 - Sun
	//other - Planets
	if (targetObject == 0) {
		__sendShipToObject(sol->star);
		__touristsAction(targetObject);
		__sendShipToObject(sol->star);
	}
	else {
		PlanetAbstract* planet = __getRandomPlanet(sol);
		__sendShipToObject(planet);
		__touristsAction(targetObject);
		__sendShipToEarth(planet);
	}
	__landShipOnStation();
	__removePassengersFromBoard();
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
