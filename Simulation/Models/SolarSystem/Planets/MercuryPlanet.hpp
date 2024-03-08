#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class MercuryPlanet : public PlanetAbstract {
public:
	MercuryPlanet(long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum) : PlanetAbstract(mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum) { std::cout << "Mercury Planet Generated...\n"; };

	MercuryPlanet() : PlanetAbstract(3E23L, 2439.7f, 59.f, 74'800'000, 87.969f, 0.4f, 700, 90, false, {}, 0.378f, 300, .00005f, 0) { std::cout << "Mercury Planet Generated...\n"; };

	~MercuryPlanet() { std::cout << "Mercury Planet Destroyed...\n"; };

	void showPlanetInfo() override;
};