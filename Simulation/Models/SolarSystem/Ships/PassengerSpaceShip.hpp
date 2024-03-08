#pragma once
#include "SpaceShipAbstract.hpp"

#include <iostream>

class PassengerSpaceShip : public SpaceShipAbstract {
public:
	PassengerSpaceShip() { std::cout << "Passenger Space Ship started engine...\n"; }

	~PassengerSpaceShip() { std::cout << "Passenger Space Ship stopped engine...\n"; }
};