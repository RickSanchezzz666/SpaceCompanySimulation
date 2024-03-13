#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override { std::cout << "Passenger ship (id: " + std::to_string(this->shipId) + ") started engine...\n"; }
	void __stopEngine() override { std::cout << "Passenger ship (id: " + std::to_string(this->shipId) + ") stopped engine...\n"; }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) { std::cout << "Passenger Space Ship (id: " + std::to_string(this->shipId) + ") generated...\n"; }

	~PassengerSpaceShip() { std::cout << "Passenger Space Ship (id: " + std::to_string(this->shipId) + ") destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum) override;

};