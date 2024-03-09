#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class MiningSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override { std::cout << "Mining ship started engine...\n"; }
	void __stopEngine() override { std::cout << "Mining ship stopped engine...\n"; }
public:
	MiningSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::MINING, 8, id) { std::cout << "Mining Space Ship generated...\n"; }

	~MiningSpaceShip() { std::cout << "Mining Space Ship destroyed...\n"; }

	void launchShip() override;
};