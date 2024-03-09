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
	std::vector<Thread*> launchThreads;

	short int __astronautsNumOnTheStation = 40;
	std::vector<SpaceShipAbstract*> __availableSpaceShips;

	std::vector<SpaceShipAbstract*> __spaceShipsInFlight;

	std::vector<SpaceShipAbstract*> __everyShip;

	short int __shipsNumber = 0;
	//balance

	void __addAstronautsNumber(int num);
	bool __decreaseAstronautsNumber(int num);

	void __makeShipAvailable(const int shipId);
	void __makeShipInFlight(const int shipId);

	bool __checkIfShipIsAvailable(const int shipId);

	SpaceShipAbstract* __findShipById(const int shipId);

	void __setSpaceShipsStatus(const int shipId, SpaceShipStatus status);

	//void __getShipType();

public:
	EarthStation() {
		for (size_t i = 0; i < static_cast<int>(SpaceShipType::TYPE_COUNT); ++i) {
			for (size_t j = 0; j < 2; ++j) {
				if (i == 0) {
					__availableSpaceShips.push_back(new ExplorerSpaceShip(__shipsNumber++));
				}
				else if (i == 1) {
					__availableSpaceShips.push_back(new MiningSpaceShip(__shipsNumber++));
				}
				else if (i == 2) {
					__availableSpaceShips.push_back(new PassengerSpaceShip(__shipsNumber++));
				}
			}
		}
		for (auto& ship : __availableSpaceShips) {
			__everyShip.push_back(ship);
		}
		std::cout << "Earth Station generated...\n";
	};

	~EarthStation() { 
		for (auto& ship : __everyShip) {
			delete ship;
		}
		__everyShip.clear();
		__availableSpaceShips.clear();
		__spaceShipsInFlight.clear();
		std::cout << "Earth Station destroyed...\n";
	}
	
	void launchSpaceShip(int num);

	int getAstronautsNumber();
	void getAvailableSpaceShips();
	void getSpaceShipsInFlight();
};