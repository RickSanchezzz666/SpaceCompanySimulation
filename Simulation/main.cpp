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
	SolarSystem solarSystem;

	solarSystem.star->showStarInfo();

	for (auto& planet : solarSystem.planets) planet->showPlanetInfo();

	solarSystem.earthStation->launchSpaceShip(0);
	solarSystem.earthStation->launchSpaceShip(1);
	solarSystem.earthStation->launchSpaceShip(2);

	std::cin.get();
	return 0;
}