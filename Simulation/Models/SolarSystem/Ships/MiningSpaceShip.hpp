#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>

class MiningSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override;
	void __stopEngine() override { std::cout << ">Mining Ship (id: " + std::to_string(this->shipId) + ") stopped engine...\n"; }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }
public:
	MiningSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::MINING, 8, id) { std::cout << ">Mining Space Ship (id: " + std::to_string(this->shipId) + ") generated...\n"; }

	~MiningSpaceShip() { std::cout << ">Mining Space Ship (id: " + std::to_string(this->shipId) + ") destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum) override;
};