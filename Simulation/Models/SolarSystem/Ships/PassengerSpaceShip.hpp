#pragma once
#include "SpaceShipAbstract.hpp"
#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	void __startEngine() override { std::cout << "Passenger ship started engine...\n"; }
	void __stopEngine() override { std::cout << "Passenger ship stopped engine...\n"; }
public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) { std::cout << "Passenger Space Ship generated...\n"; }

	~PassengerSpaceShip() { std::cout << "Passenger Space Ship destroyed...\n"; }

	void launchShip() override;

};