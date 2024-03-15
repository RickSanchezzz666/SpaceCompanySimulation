#include "PassengerSpaceShip.hpp"

void PassengerSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") is launching in: " + std::to_string(i) + "\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") started engine...\n";
}

void PassengerSpaceShip::__getPassengersOnBoard(const int passengersNum) { 
	__currPassengersAmount.fetch_add(passengersNum, std::memory_order_relaxed); 
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") boarded " + std::to_string(passengersNum) + " passengers..\n";
}

void PassengerSpaceShip::__removePassengersFromBoard() { 
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") " + std::to_string(__currPassengersAmount) + " passengers left a board..\n";
	__currPassengersAmount = 0;
}


void PassengerSpaceShip::launchShip(std::atomic<short>& astroNum) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	std::cout << "\n>Passenger Ship (id: " + std::to_string(this->shipId) + ") is preparing for a flight..\n";
	__getPassengersOnBoard(20);
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") is launching..\n";
	this->__startEngine();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") set his goal of reaching Venus..\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") is currently heading Venus..\n";
	std::this_thread::sleep_for(std::chrono::seconds(20));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") reached Venus's orbit..\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") is currently orbiting Venus..\n";
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") started heading back to Earth..\n";
	std::this_thread::sleep_for(std::chrono::seconds(20));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") is on Earth's orbit..\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") began to enter the Earth's atmosphere..\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") succesfully landed on Earth's Station..\n";
	this->__stopEngine();
	__removePassengersFromBoard();
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
