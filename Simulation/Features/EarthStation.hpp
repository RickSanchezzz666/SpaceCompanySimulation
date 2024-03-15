#pragma once
#include "../Models/SolarSystem/Ships/SpaceShipAbstract.hpp"
#include "../Models/SolarSystem/Ships/MiningSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/ExplorerSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/PassengerSpaceShip.hpp"
#include "../Models/SolarSystem/Ships/SpaceShipType.hpp"
#include "../Models/SolarSystem/SolarSystem.hpp"

#include "Balance.hpp"

#include "../../Threads/Thread.hpp"

#include <iostream>
#include <vector>
#include <atomic>

class EarthStation {
private:
	std::vector<Thread*> launchThreads;

	std::atomic<short> __astronautsNumOnTheStation = 40;

	std::vector<SpaceShipAbstract*> __everyShip;

	short int __shipsNumber = 0;

	SpaceShipAbstract* __findShipById(const int shipId);

	void __setSpaceShipsStatus(const int shipId, const SpaceShipStatus status);

	bool __checkIfShipIsAvailable(const int shipId);

	//void __getShipType();

public:
	Balance* balance;

	SolarSystem* solarSystem = nullptr;

	EarthStation(SolarSystem* sol) {
		balance = new Balance(100);
		solarSystem = sol;
		for (size_t i = 0; i < static_cast<int>(SpaceShipType::TYPE_COUNT); ++i) {
			for (size_t j = 0; j < 2; ++j) {
				if (i == 0) {
					__everyShip.push_back(new ExplorerSpaceShip(__shipsNumber++));
				}
				else if (i == 1) {
					__everyShip.push_back(new MiningSpaceShip(__shipsNumber++));
				}
				else if (i == 2) {
					__everyShip.push_back(new PassengerSpaceShip(__shipsNumber++));
				}
			}
		}
		std::cout << "Earth Station generated...\n";
	};

	~EarthStation() { 
		for (auto& ship : __everyShip) delete ship;
		__everyShip.clear();
		std::cout << "Earth Station destroyed...\n";
	}
	
	void launchSpaceShip(const int shipId);

	bool checkIfShipIsAvailable(const int shipId);

	int getAstronautsNumber();

	int getShipsNumber() { return __shipsNumber; }

	void displayAvailableSpaceShips();
	void displaySpaceShipsInFlight();

	void displayEveryShip();
};