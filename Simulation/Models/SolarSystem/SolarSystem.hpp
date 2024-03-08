#pragma once
#include "Stars/SunStar.hpp"
#include "Planets/PlanetAbstract.hpp"
#include "Planets/MercuryPlanet.hpp"
#include "Planets/VenusPlanet.hpp"
#include "Planets/MarsPlanet.hpp"

#include <vector>
#include <iostream>

class SolarSystem {
public:
	static SunStar* star;
	static std::vector<PlanetAbstract*> planets;


	SolarSystem() { star = new SunStar();
		planets.push_back(new MercuryPlanet());
		planets.push_back(new VenusPlanet());
		planets.push_back(new MarsPlanet());
		std::cout << "Solar System generated...\n";
	};

	~SolarSystem() {
		delete star;
		for (auto& planet : planets) delete planet;
		std::cout << "Solar System destroyed...\n";
	}
};