#pragma once

#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <thread>
#include <chrono>

class SpaceShipAbstract {
public:
	SpaceShipStatus spaceShipStatus = SpaceShipStatus::AVAILABLE;
	const SpaceShipType spaceShipType;

	SpaceShipAbstract(SpaceShipStatus status, SpaceShipType type) : spaceShipStatus(status), spaceShipType(type) {}

	virtual void startEngine() = 0;
	virtual void stopEngine() = 0;

	virtual void launchShip() = 0;
};