#pragma once

#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <thread>
#include <chrono>
#include <atomic>

class SpaceShipAbstract {
private:
	virtual void __startEngine() = 0;
	virtual void __stopEngine() = 0;

	virtual void __setSpaceShipsStatus(SpaceShipStatus status) = 0;
	
protected:
	void __increaseAstronautsNumber(std::atomic<short>& astroNum, const int num) {
		astroNum.fetch_add(num, std::memory_order_relaxed);
	}
	void __decreaseAstronautsNumber(std::atomic<short>& astroNum, const int num) {
		int currentNum = astroNum;
		if ((currentNum - num) < 0) return;
		astroNum.fetch_sub(num, std::memory_order_relaxed);
	}

public:
	SpaceShipStatus spaceShipStatus = SpaceShipStatus::AVAILABLE;
	const SpaceShipType spaceShipType;
	const int requiredAstronautsNumber;
	const int shipId;

	SpaceShipAbstract(SpaceShipStatus status, SpaceShipType type, int astroNumber, int id) : spaceShipStatus(status), spaceShipType(type), requiredAstronautsNumber(astroNumber), shipId(id) {}

	virtual void launchShip(std::atomic<short>& astroNum) = 0;
};