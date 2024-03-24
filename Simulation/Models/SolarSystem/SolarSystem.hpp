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

#include <vector>
#include <iostream>

class SolarSystem {
public:
	SunStar* star;
	std::vector<PlanetAbstract*> planets;


	SolarSystem() { star = new SunStar();
		planets.push_back(new MercuryPlanet());
		planets.push_back(new VenusPlanet());
		planets.push_back(new MarsPlanet());
		planets.push_back(new JupiterPlanet());
		planets.push_back(new SaturnPlanet());
		planets.push_back(new UranusPlanet());
		planets.push_back(new NeptunePlanet());
		std::cout << "Solar System generated...\n";
	};

	~SolarSystem() {
		delete star;
		for (auto& planet : planets) delete planet;
		std::cout << "Solar System destroyed...\n";
	}
};