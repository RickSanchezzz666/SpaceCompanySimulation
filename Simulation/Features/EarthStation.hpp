#pragma once
#include "../Models/SolarSystem/Ships/SpaceShipAbstract.hpp"
#include "../Models/SolarSystem/Ships/MiningSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/ExplorerSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/PassengerSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/SpaceShipType.hpp"

#include "../../Threads/Thread.hpp"

#include <iostream>
#include <vector>

class EarthStation {
private:
	short int __astronautsNum = 40;
	std::vector<std::vector<SpaceShipAbstract*>> __availableSpaceShips;
	std::vector<SpaceShipAbstract*> __spaceShipsInFlight;
	//balance

	void __getAstronautsNumber();
	void __addAstronautsNumber();
	void __decreaseAstronatusNumber();

	void __makeShipAvailable();
	void __makeShipInFlight();

	void __setSpaceShipsStatus();

	
	//void __getShipType();

public:
	EarthStation() {
		for (size_t i = 0; i < static_cast<int>(SpaceShipType::TYPE_COUNT); ++i) {
			__availableSpaceShips.push_back({});
			for (size_t j = 0; j < 2; ++j) {
				if (i == 0) __availableSpaceShips[i].push_back(new ExplorerSpaceShip());
				else if (i == 1) __availableSpaceShips[i].push_back(new MiningSpaceShip());
				else if (i == 2) __availableSpaceShips[i].push_back(new PassengerSpaceShip());
			}
		}
		std::cout << "Earth Station generated...\n";
	};

	~EarthStation() { std::cout << "Earth Station destroyed...\n"; }
	
	void launchS(int num);

	void getAvailableSpaceShips();
	void getSpaceShipsInFlight();
};