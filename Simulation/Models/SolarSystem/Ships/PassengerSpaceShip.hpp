#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>
#include <atomic>

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	std::atomic<int> __currPassengersAmount = 0;

	void __startEngine() override;
	void __stopEngine() override { std::cout << ">Passenger Ship (id: " + std::to_string(this->shipId) + ") stopped engine...\n"; }
	void __getPassengersOnBoard(const int passengersNum);
	void __removePassengersFromBoard();

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) { std::cout << ">Passenger Space Ship (id: " + std::to_string(this->shipId) + ") generated...\n"; }

	~PassengerSpaceShip() { std::cout << ">Passenger Space Ship (id: " + std::to_string(this->shipId) + ") destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum) override;

};