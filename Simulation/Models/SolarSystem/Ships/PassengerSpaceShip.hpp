#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class PassengerSpaceShip : public SpaceShipAbstract {
public:
	PassengerSpaceShip() : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER) { std::cout << "Passenger Space Ship generated...\n"; }

	~PassengerSpaceShip() { std::cout << "Passenger Space Ship destroyed...\n"; }

	void startEngine() override { std::cout << "Explorer ship started engine..."; }
	void stopEngine() override { std::cout << "Explorer ship stopped engine..."; }
};