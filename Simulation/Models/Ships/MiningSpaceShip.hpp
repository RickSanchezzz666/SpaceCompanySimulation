#pragma once
#include "SpaceShipAbstract.hpp"

class MiningSpaceShip : public SpaceShipAbstract {
public:
	void startEngine() override;

	void stopEngine() override;
};