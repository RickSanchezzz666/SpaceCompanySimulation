#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class ExplorerSpaceShip : public SpaceShipAbstract {
public:
	ExplorerSpaceShip() : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER) { std::cout << "Explorer Space Ship generated...\n"; }

	~ExplorerSpaceShip() { std::cout << "Explorer Space Ship destroyed...\n"; }

	void startEngine() override { std::cout << "Explorer ship started engine...\n"; }
	void stopEngine() override { std::cout << "Explorer ship stopped engine...\n"; }

	void launchShip() override;
};