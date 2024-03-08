#pragma once
#include "SpaceShipAbstract.hpp"

#include <iostream>

class MiningSpaceShip : public SpaceShipAbstract {
public:
	MiningSpaceShip() { std::cout << "Mining Space Ship started engine...\n"; }

	~MiningSpaceShip() { std::cout << "Mining Space Ship stopped engine...\n"; }
};