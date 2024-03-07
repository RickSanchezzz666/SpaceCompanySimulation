#pragma once
#include "SpaceShipAbstract.hpp"

class ExplorerSpaceShip : public SpaceShipAbstract {
public:
	void startEngine() override;

	void stopEngine() override;
};