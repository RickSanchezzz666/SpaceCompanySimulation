#include "Models/Ships/PassengerSpaceShip.hpp"
#include "Models/Ships/MiningSpaceShip.hpp"
#include "Models/Ships/ExplorerSpaceShip.hpp"

#include "Models/Planets/MercuryPlanet.hpp"
#include "Models/Planets/VenusPlanet.hpp"
#include "Models/Planets/MarsPlanet.hpp"

#include <iostream>

int main() {
	PassengerSpaceShip pShip;
	MiningSpaceShip mShip;
	ExplorerSpaceShip eShip;


	MercuryPlanet pMercury(3E23L, 2439.7f, 59.f, 74'800'000, 87.969f, 0.4f, 700, 90, false, {}, 0.378f, 300, .00005f, 0);
	VenusPlanet pVenus(4.867E24L, 6051.8f, 243.025f, 460'200'000, 224.7f, 0.72, 464, 462, true, { {"Carbon Dioxide (CO2)", 96.5}, 
																								{"Nitrogen (N)", 3.5} }, 0.907f, 0, .0f, 0);
	MarsPlanet pMars(6.417E23L, 3389.5f, 1.025f, 144'800'000, 687.0f,1.52f, 35, -143, true, 
								{ {"Carbon Dioxide (CO2)", 95.32},
								{"Nitrogen (N)", 2.7},
								{"Argon (Ar)", 1.6},
								{"Oxygen (O2)", 0.13} }, 0.377f, 0, 0.005f, 2);

	pShip.startEngine();
	pShip.stopEngine();

	mShip.startEngine();
	mShip.stopEngine();

	eShip.startEngine();
	eShip.stopEngine();

	pMercury.generatePlanet();
	pMercury.destroyPlanet();
	pMercury.showPlanetInfo();

	pVenus.generatePlanet();
	pVenus.destroyPlanet();
	pVenus.showPlanetInfo();

	pMars.generatePlanet();
	pMars.destroyPlanet();
	pMars.showPlanetInfo();

	
	std::cin.get();
	return 0;
}