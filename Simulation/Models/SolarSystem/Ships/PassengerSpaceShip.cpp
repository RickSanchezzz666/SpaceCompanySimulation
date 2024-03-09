#include "PassengerSpaceShip.hpp"

void PassengerSpaceShip::launchShip() {
	std::cout << "Passenger Ship is launching..\n";
	this->__startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	this->__stopEngine();
}
