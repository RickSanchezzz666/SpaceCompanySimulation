#include "Simulation.hpp"

void Simulation::__startSimulation() {
	size_t i = 5;
	int randomNum;
	while (true) {
		/*randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
		if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);*/
		if (earthStation->checkIfShipIsAvailable(5)) earthStation->launchSpaceShip(5);
		std::this_thread::sleep_for(std::chrono::seconds(6));
	}
}

void Simulation::__showInfo() {
	solarSystem->star->showStarInfo();

	for (auto& planet : solarSystem->planets) planet->showPlanetInfo();

	earthStation->displayEveryShip();
}