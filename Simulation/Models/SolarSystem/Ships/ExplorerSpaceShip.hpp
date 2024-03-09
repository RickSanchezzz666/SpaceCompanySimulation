#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class ExplorerSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override { std::cout << "Explorer ship started engine...\n"; }
	void __stopEngine() override { std::cout << "Explorer ship stopped engine...\n"; }

public:
	ExplorerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER, 6, id) { std::cout << "Explorer Space Ship generated...\n"; }

	~ExplorerSpaceShip() { std::cout << "Explorer Space Ship destroyed...\n"; }

	void launchShip() override;
};