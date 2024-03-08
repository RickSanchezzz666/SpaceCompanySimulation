#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class MiningSpaceShip : public SpaceShipAbstract {
public:
	MiningSpaceShip() : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::MINING) { std::cout << "Mining Space Ship generated...\n"; }

	~MiningSpaceShip() { std::cout << "Mining Space Ship destroyed...\n"; }

	void startEngine() override { std::cout << "Explorer ship started engine..."; }
	void stopEngine() override { std::cout << "Explorer ship stopped engine..."; }
};