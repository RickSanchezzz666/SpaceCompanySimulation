#include "EarthStation.hpp"

#include <iostream>
#include <chrono>

void EarthStation::__launchShip() {
	std::cout << "Ship is launching..\n";
	__availableSpaceShips[0][0]->startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	__availableSpaceShips[0][0]->stopEngine();
}

void EarthStation::launchShip() {
	Thread launchThread([&]() { __launchShip(); });
}