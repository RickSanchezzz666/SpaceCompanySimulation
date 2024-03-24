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

	int __expeditionNum = 0;

	std::vector<int> __objectsSearched;
	std::vector<std::string> _exploredData;

	void __doExploration(SolarSystem* sol, PlanetAbstract* planet);
	void __doExploration(SolarSystem* sol, StarsAbstract* sun);
	void __continueExploration(SolarSystem* sol, std::string objName);

	void __concludeExploration();

	void __sendShipToObject(PlanetAbstract* planet) override;
	void __sendShipToObject(StarsAbstract* sun) override;
	void __sendShipToEarth(PlanetAbstract* planet) override;
	void __sendShipToEarth(StarsAbstract* sun) override;
	void __landShipOnStation() override;

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }

	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	ExplorerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::EXPLORER, 6, id) { std::cout << shipSign + " generated...\n"; }

	~ExplorerSpaceShip() { std::cout << shipSign + " destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;
};