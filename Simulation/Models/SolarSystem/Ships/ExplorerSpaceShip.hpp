#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <vector>
#include <string>

class ExplorerSpaceShip : public SpaceShipAbstract {
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

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	ExplorerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER, 6, id) {}

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;
};