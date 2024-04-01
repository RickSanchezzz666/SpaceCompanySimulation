#include "Simulation.hpp"

void Simulation::__launchShip() {
	int randomShip = getRandomNumber(0, earthStation->getShipsNumber() - 1);
	if (earthStation->checkIfShipIsAvailable(randomShip)) {
		earthStation->showAstronautsNumber();
		earthStation->displayAvailableSpaceShips();
		earthStation->launchSpaceShip(randomShip);
	}
	else {
		if (firstLaunch) {
			__launchShip();
			firstLaunch = false;
		}
	}
}

void Simulation::__startSimulation() {
	while (true) {
		__launchShip();
		std::this_thread::sleep_for(std::chrono::seconds(Random::getRandomNumber(5, 25)));
		__launchShip();
		if (earthStation->getShipBusyShipsNumber() >= 2) std::this_thread::sleep_for(std::chrono::seconds(Random::getRandomNumber(30, 180)));
	}
	
}

void Simulation::__showInfo() {
	earthStation->displayEveryShip();
}