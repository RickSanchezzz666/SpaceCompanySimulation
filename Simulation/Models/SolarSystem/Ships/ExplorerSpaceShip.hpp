#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

class ExplorerSpaceShip : public SpaceShipAbstract {
private:
	// Key - Object, (Visit Price, Moon Price, Asteroid Price)
	std::unordered_map<std::string, std::tuple<int, int, int>> __explorerRevenue = {
		{"Sun", {std::make_tuple(50'000, 0, 31'632)}},
		{"Mercury", {std::make_tuple(10'000, 0, 0)}},
		{"Venus", {std::make_tuple(10'000, 0, 0)}},
		{"Mars", {std::make_tuple(12'000, 53'853, 0)}},
		{"Jupiter", {std::make_tuple(20'000, 16'021, 29'504)}},
		{"Saturn", {std::make_tuple(20'000, 17'457, 83'463)}},
		{"Uranus", {std::make_tuple(15'000, 11'963, 24'405)}},
		{"Neptune", {std::make_tuple(15'000, 13'457, 25'632)}},
	};
private:
	const std::string shipSign = " >Explorer Ship (id: " + std::to_string(this->shipId) + ")";

	std::vector<VisitedObject> __objectsSearched;
	std::vector<std::tuple<std::string, std::string>> _exploredData; // (Moon, Planet)
	std::vector<std::tuple<std::string, std::string>> _exploredDataClusters; // (Asteroid, Orbit)

	void __doExploration(SolarSystem* sol, PlanetAbstract* planet);
	void __doExploration(SolarSystem* sol, StarsAbstract* sun);
	void __continueExploration(SolarSystem* sol, std::string objName);

	void __concludeExploration();

	void __sendShipToObject(SolarSystem* sol, PlanetAbstract* planet) override;
	void __sendShipToObject(SolarSystem* sol, StarsAbstract* sun) override;
	void __sendShipToEarth(SolarSystem* sol, PlanetAbstract* planet) override;
	void __sendShipToEarth(SolarSystem* sol, StarsAbstract* sun) override;
	void __landShipOnStation() override;

	int __calculateRevenue() override;
	int __getPrice(std::string& obj, const int type); // Type (0 - Visit, 1 - Moon, 2 - Cluster)

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	ExplorerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER, 6, id) {}

	int launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;
};