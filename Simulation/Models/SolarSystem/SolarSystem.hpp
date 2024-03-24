#pragma once
#include "Stars/SunStar.hpp"
#include "Planets/PlanetAbstract.hpp"
#include "Planets/MercuryPlanet.hpp"
#include "Planets/VenusPlanet.hpp"
#include "Planets/MarsPlanet.hpp"
#include "Planets/JupiterPlanet.hpp"
#include "Planets/SaturnPlanet.hpp"
#include "Planets/UranusPlanet.hpp"
#include "Planets/NeptunePlanet.hpp"
#include "AsteroidCluster.hpp"

#include <vector>
#include <iostream>

class SolarSystem {
public:
	SunStar* star;
	std::vector<PlanetAbstract*> planets;
	std::vector<AsteroidCluster*> asteroidClusters;

	SolarSystem() { star = new SunStar();
		planets.push_back(new MercuryPlanet());
		planets.push_back(new VenusPlanet());
		planets.push_back(new MarsPlanet());
		planets.push_back(new JupiterPlanet());
		planets.push_back(new SaturnPlanet());
		planets.push_back(new UranusPlanet());
		planets.push_back(new NeptunePlanet());

		asteroidClusters.push_back(new AsteroidCluster("Asteroid Belt", "Sun", 92'000'000, { "C-type", "M-type", "S-type" }));
		asteroidClusters.push_back(new AsteroidCluster("Jupiter Trojans", "Sun", 200, { "C-type", "D-type" }));
		asteroidClusters.push_back(new AsteroidCluster("Kuiper Belt", "Sun", 5'983'914'830, { "C-type", "M-type" }));
		std::cout << "Solar System generated...\n";
	};

	~SolarSystem() {
		delete star;
		for (auto& planet : planets) delete planet;
		for (auto& asteroids : asteroidClusters) delete asteroids;
		std::cout << "Solar System destroyed...\n";
	}
};