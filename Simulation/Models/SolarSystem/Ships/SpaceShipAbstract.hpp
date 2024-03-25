#pragma once

#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"
#include "../SolarSystem.hpp"
#include "../../../Features/Random.hpp"

#include <thread>
#include <chrono>
#include <atomic>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <tuple>

enum class ShipCurrentStatus {
	STARTING,
	LANDED,
	INFLIGHT,
	LANDING
};

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

	PlanetAbstract* __getRandomPlanet(SolarSystem* sol) const {
		return sol->planets[Random::getRandomNumber(0, sol->planets.size() - 1)];
	}

	AsteroidCluster* __getRandomCluster(SolarSystem* sol) const {
		AsteroidCluster* cluster = nullptr;
		do {
			if (sol->isEveryClusterExplored()) return nullptr;
			cluster = sol->asteroidClusters[Random::getRandomNumber(0, sol->asteroidClusters.size() - 1)];
		} while (cluster->clusterStatus == AsteroidStatus::EXPLORED);
		return cluster;
	}

	PlanetAbstract* __getPlanet(SolarSystem* sol, int index) const {
		return sol->planets[index];
	}

	AsteroidCluster* __getCluster(PlanetAbstract* planet) const { return planet->asteroidBelt; }

	virtual void __sendShipToObject(PlanetAbstract* planet) = 0;
	virtual void __sendShipToObject(StarsAbstract* sun) = 0;
	virtual void __sendShipToEarth(PlanetAbstract* planet) = 0;
	virtual void __sendShipToEarth(StarsAbstract* sun) = 0;
	virtual void __landShipOnStation() = 0;

	std::string __getCurrentTimestamp() {
		auto now = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(now);
		std::tm timeinfo;
		localtime_s(&timeinfo, &time);

		std::ostringstream oss;
		oss << "[" << std::put_time(&timeinfo, "%H:%M:%S") << "]";
		return oss.str();
	}

public:
	SpaceShipStatus spaceShipStatus = SpaceShipStatus::AVAILABLE;
	const SpaceShipType spaceShipType;
	const int requiredAstronautsNumber;
	const int shipId;
	ShipCurrentStatus currentStatus = ShipCurrentStatus::LANDED;

	void changeShipStatus(ShipCurrentStatus status) {
		this->currentStatus = status;
	}

	void printMessage(const std::string& msg, bool withEndl = false) {
		if (withEndl) {
			std::cout << "\n" + __getCurrentTimestamp() + msg;
		}
		else {
			std::cout << __getCurrentTimestamp() + msg;
		}
	}

	void threadSleep(int sec) {
		std::this_thread::sleep_for(std::chrono::seconds(sec));
	}

	SpaceShipAbstract(SpaceShipStatus status, SpaceShipType type, int astroNumber, int id) : spaceShipStatus(status), spaceShipType(type), requiredAstronautsNumber(astroNumber), shipId(id) {}

	virtual void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) = 0;
};