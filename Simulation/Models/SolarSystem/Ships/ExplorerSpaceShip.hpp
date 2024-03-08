#pragma once
#include "SpaceShipAbstract.hpp"

#include <iostream>

class ExplorerSpaceShip : public SpaceShipAbstract {
public:
	ExplorerSpaceShip() { std::cout << "Explorer Space Ship started engine...\n"; }

	~ExplorerSpaceShip() { std::cout << "Explorer Space Ship stopped engine...\n"; }
};