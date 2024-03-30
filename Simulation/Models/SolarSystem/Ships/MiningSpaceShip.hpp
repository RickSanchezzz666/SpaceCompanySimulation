#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>
#include <tuple>
#include <atomic>
#include <unordered_map>

class MiningSpaceShip : public SpaceShipAbstract {
private:
	const std::string shipSign = " >Mining Ship (id: " + std::to_string(this->shipId) + ")";

	std::atomic<int> __numberOfLimpetDrones = 0;

	std::vector<VisitedObject> __objectsVisited; // (Asteroid, Orbit)

	std::vector<std::tuple<std::string, int>> __minedResourses; // (Element, Amount)

	void __getLimpetDrones(const int number) { 
		__numberOfLimpetDrones.fetch_add(number, std::memory_order_relaxed);
		printMessage(shipSign + " got " + std::to_string(number) + " Limpet Drones for Mining..\n");
	}

	void __decreaseNumberOfLimpetDrones(const int number = 1) {
		__numberOfLimpetDrones.fetch_sub(number, std::memory_order_relaxed);
	}

	void __removeLimpetDrones() { __numberOfLimpetDrones = 0; }

	std::string __getElementFromAsteroid(const int& chance, std::vector<std::tuple<std::string, int>>& components);

	std::unordered_map<std::string, int> __calculateCollectedResources();
	void __concludeMining();

	void __sendShipToCluster(SolarSystem* sol, AsteroidCluster* cluster);
	void __sendShipToEarth(SolarSystem* sol, AsteroidCluster* cluster);

	void __miningActions(SolarSystem* sol, AsteroidCluster* cluster);
	void __doMining(SolarSystem* sol, AsteroidCluster* cluster);

	void __sendShipToObject(SolarSystem* sol, PlanetAbstract* planet) override {};
	void __sendShipToObject(SolarSystem* sol, StarsAbstract* sun) override {};
	void __sendShipToEarth(SolarSystem* sol, PlanetAbstract* planet) override {};
	void __sendShipToEarth(SolarSystem* sol, StarsAbstract* sun) override {};
	void __landShipOnStation() override;

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }
public:
	MiningSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::MINING, 8, id) {}

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;
};