#include "Simulation.hpp"

void Simulation::__startSimulation() {
	size_t i = 5;
	int randomNum;
	//while (true) {
	//	/*randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
	//	if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);*/
	//	if (earthStation->checkIfShipIsAvailable(0)) earthStation->launchSpaceShip(0);
	//	std::this_thread::sleep_for(std::chrono::seconds(11));
	//	if (earthStation->checkIfShipIsAvailable(4)) earthStation->launchSpaceShip(4);
	//}

	if (earthStation->checkIfShipIsAvailable(0)) earthStation->launchSpaceShip(0);
	std::this_thread::sleep_for(std::chrono::seconds(11));
	if (earthStation->checkIfShipIsAvailable(4)) earthStation->launchSpaceShip(4);
}

void Simulation::__showInfo() {
	earthStation->displayEveryShip();
}