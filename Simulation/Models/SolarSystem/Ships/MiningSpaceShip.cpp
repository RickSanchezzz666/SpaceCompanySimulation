#include "MiningSpaceShip.hpp"

void MiningSpaceShip::launchShip() {
	std::cout << "Mining Ship is launching..\n";
	this->__startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	this->__stopEngine();
}
