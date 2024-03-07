#include "Models/SolarSystem/Ships/PassengerSpaceShip.hpp"
#include "Models/SolarSystem/Ships/MiningSpaceShip.hpp"
#include "Models/SolarSystem/Ships/ExplorerSpaceShip.hpp"

#include "Models/SolarSystem/Planets/MercuryPlanet.hpp"
#include "Models/SolarSystem/Planets/VenusPlanet.hpp"
#include "Models/SolarSystem/Planets/MarsPlanet.hpp"

#include "Models/SolarSystem/Stars/SunStar.hpp"

#include "Models/SolarSystem/SolarSystem.hpp"

#include <iostream>

int main() {
	PassengerSpaceShip pShip;
	MiningSpaceShip mShip;
	ExplorerSpaceShip eShip;

	SolarSystem solarSystem;

	pShip.startEngine();
	pShip.stopEngine();

	mShip.startEngine();
	mShip.stopEngine();

	eShip.startEngine();
	eShip.stopEngine();

	for (auto& planet : solarSystem.planets) {
		planet->generatePlanet();
		planet->showPlanetInfo();
		planet->destroyPlanet();
	}
	
	solarSystem.star->generateStar();
	solarSystem.star->showStarInfo();
	solarSystem.star->destroyStar();

	std::cin.get();
	return 0;
}