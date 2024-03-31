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
	/*if (earthStation->checkIfShipIsAvailable(0)) earthStation->launchSpaceShip(0);
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(20));
		
	}*/
	solarSystem->makeClusterExplored(solarSystem->asteroidClusters[0]);
	if (earthStation->checkIfShipIsAvailable(2)) earthStation->launchSpaceShip(2);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	if (earthStation->checkIfShipIsAvailable(3)) earthStation->launchSpaceShip(3);
}

void Simulation::__showInfo() {
	earthStation->displayEveryShip();
}