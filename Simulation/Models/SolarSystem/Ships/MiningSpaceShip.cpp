#include "MiningSpaceShip.hpp"

void MiningSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		std::cout << ">Mining Ship (id: " + std::to_string(this->shipId) + ") is launching in: " + std::to_string(i) + "\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << ">Mining Ship (id: " + std::to_string(this->shipId) + ") started engine...\n";
}

void MiningSpaceShip::launchShip(std::atomic<short>& astroNum) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	std::cout << "\n>Mining Ship (id: " + std::to_string(this->shipId) + ") is preparing for a flight..\n";
	std::cout << ">Mining Ship (id: " + std::to_string(this->shipId) + ") is launching..\n";
	this->__startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	this->__stopEngine();
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
