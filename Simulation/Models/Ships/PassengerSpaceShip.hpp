#pragma once
#include "SpaceShipAbstract.hpp"

class PassengerSpaceShip : public SpaceShipAbstract {
public:
	void startEngine() override;

	void stopEngine() override;
};