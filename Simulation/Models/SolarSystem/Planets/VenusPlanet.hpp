#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class VenusPlanet : public PlanetAbstract {
public:
	VenusPlanet(std::string name, long double mass, float radius, float day, long double area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, std::vector<std::string> moons, int id, bool belt, std::string type) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, moons, id, belt, type) {};

	VenusPlanet() : PlanetAbstract("Venus", 4.867E24L, 6051.8f, 243.025f, 460'200'000, 224.7f, 0.72f, 464, 462, true, { {"Carbon Dioxide (CO2)", 96.5},
																								{"Nitrogen (N)", 3.5} }, 0.907f, 0, .0f, 0, {}, 2, false, "High metal content world") {};
};