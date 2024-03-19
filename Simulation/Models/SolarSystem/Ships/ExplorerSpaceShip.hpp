#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>

class ExplorerSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override;
	void __stopEngine() override { std::cout << ">Explorer Ship (id: " + std::to_string(this->shipId) + ") stopped engine...\n"; }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	ExplorerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER, 6, id) { std::cout << ">Explorer Space Ship (id: " + std::to_string(this->shipId) + ") generated...\n"; }

	~ExplorerSpaceShip() { std::cout << ">Explorer Space Ship (id: " + std::to_string(this->shipId) + ") destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;
};