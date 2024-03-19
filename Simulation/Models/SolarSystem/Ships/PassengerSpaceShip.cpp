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

void PassengerSpaceShip::__sendShipToPlanet(SolarSystem* sol) {
	PlanetAbstract* planet = __getRandomPlanet(sol);
	threadSleep(2);
	std::cout << shipSign + " route is set with the goal of reaching " + planet->_name + "..\n";
	threadSleep(5);
	std::cout << shipSign + " left Earth's atmosphere..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently heading " + planet->_name + "..\n";
	threadSleep(planet->timeFromEarthToPlanet);
	std::cout << shipSign + " reached " + planet->_name + "'s orbit..\n";
	threadSleep(2);
	std::cout << shipSign + " is currently orbiting " + planet->_name + "..\n";
	threadSleep(5);
	std::cout << shipSign + " started heading back to Earth..\n";
	threadSleep(planet->timeFromEarthToPlanet);
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
	__sendShipToPlanet(sol);
	__removePassengersFromBoard();
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
