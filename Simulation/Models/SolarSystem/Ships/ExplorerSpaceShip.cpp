#include "ExplorerSpaceShip.hpp"

void ExplorerSpaceShip::launchShip() {
	std::cout << "Explorer Ship is launching..\n";
	this->startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	this->stopEngine();
}
