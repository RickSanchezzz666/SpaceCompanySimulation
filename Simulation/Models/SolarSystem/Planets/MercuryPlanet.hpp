#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class MercuryPlanet : public PlanetAbstract {
public:
	MercuryPlanet(std::string name, long double mass, float radius, float day, long double area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, std::vector<std::string> moons, int id, bool belt, std::string type) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, moons, id, belt, type) {};

	MercuryPlanet() : PlanetAbstract("Mercury", 3E23L, 2439.7f, 59.f, 74'800'000, 87.969f, 0.4f, 700, 90, false, {}, 0.378f, 300, .00005f, 0, {}, 1, false, "Metal-rich") {};
};