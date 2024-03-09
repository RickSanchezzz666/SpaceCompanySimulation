#pragma once

#include "../../../Features/SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <thread>
#include <chrono>

class SpaceShipAbstract {
private:
	virtual void __startEngine() = 0;
	virtual void __stopEngine() = 0;
public:
	SpaceShipStatus spaceShipStatus = SpaceShipStatus::AVAILABLE;
	const SpaceShipType spaceShipType;
	const int requiredAstronautsNumber;
	const int shipId;

	SpaceShipAbstract(SpaceShipStatus status, SpaceShipType type, int astroNumber, int id) : spaceShipStatus(status), spaceShipType(type), requiredAstronautsNumber(astroNumber), shipId(id) {}

	virtual void launchShip() = 0;
};