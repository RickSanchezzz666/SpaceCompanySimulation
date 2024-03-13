#pragma once
#include "Models/SolarSystem/SolarSystem.hpp"
#include "Features/Random.hpp"

#include <iostream>
#include <thread>
#include <chrono>

class Simulation : Random {
private:
	SolarSystem* solarSystem;
	EarthStation* eStation;

	void __startSimulation() {
		size_t i = 1;
		int randomNum;
		while (i < 7) {
			randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
			if (eStation->checkIfShipIsAvailable(0)) eStation->launchSpaceShip(0);
			randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
			if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);
			randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
			if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);

			std::this_thread::sleep_for(std::chrono::seconds(i));

			if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);
			randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);
			if (eStation->checkIfShipIsAvailable(randomNum)) eStation->launchSpaceShip(randomNum);
			randomNum = getRandomNumber(0, eStation->getShipsNumber() - 1);

			std::this_thread::sleep_for(std::chrono::seconds(i));
			++i;
		}
	}

	void __showInfo() {
		solarSystem->star->showStarInfo();

		for (auto& planet : solarSystem->planets) planet->showPlanetInfo();

		eStation->displayEveryShip();
	}
public:
	Simulation() { solarSystem = new SolarSystem();
				eStation = solarSystem->earthStation; };

	~Simulation() {
		delete solarSystem;
	}

	void startSimulation() {
		__showInfo();
		__startSimulation();
		std::cin.get();
	}

	
};