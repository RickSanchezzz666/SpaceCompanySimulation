#include "EarthStation.hpp"

#include <iostream>
#include <chrono>

void EarthStation::launchS(int num) {
	Thread* launchThread = nullptr;

	if (num == 0) {
		launchThread = new Thread([&]() { __availableSpaceShips[0][0]->launchShip(); });
	}
	else {
		launchThread = new Thread([&]() { __availableSpaceShips[0][1]->launchShip(); });
	}
}