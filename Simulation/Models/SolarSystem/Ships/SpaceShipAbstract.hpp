#pragma once

#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"
#include "../SolarSystem.hpp"
#include "../../../Features/Random.hpp"

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

	PlanetAbstract* __getRandomPlanet(SolarSystem* sol) {
		return sol->planets[Random::getRandomNumber(0, sol->planets.size() - 1)];
	}

	PlanetAbstract* __getPlanet(SolarSystem* sol, int index) {
		return sol->planets[index];
	}

	virtual void __sendShipToObject(PlanetAbstract* planet) = 0;
	virtual void __sendShipToObject(StarsAbstract* sun) = 0;
	virtual void __sendShipToEarth(PlanetAbstract* planet) = 0;
	virtual void __sendShipToEarth(StarsAbstract* sun) = 0;
	virtual void __landShipOnStation() = 0;

public:
	SpaceShipStatus spaceShipStatus = SpaceShipStatus::AVAILABLE;
	const SpaceShipType spaceShipType;
	const int requiredAstronautsNumber;
	const int shipId;

	void threadSleep(int sec) {
		std::this_thread::sleep_for(std::chrono::seconds(sec));
	}

	SpaceShipAbstract(SpaceShipStatus status, SpaceShipType type, int astroNumber, int id) : spaceShipStatus(status), spaceShipType(type), requiredAstronautsNumber(astroNumber), shipId(id) {}

	virtual void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) = 0;
};