#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class MarsPlanet : public PlanetAbstract {
public:
	MarsPlanet(long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum) : PlanetAbstract(mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum) {std::cout << "Mars Planet Generated...\n";};

	MarsPlanet() : PlanetAbstract(6.417E23L, 3389.5f, 1.025f, 144'800'000, 687.0f, 1.52f, 35, -143, true,
		{ {"Carbon Dioxide (CO2)", 95.32},
		{"Nitrogen (N)", 2.7},
		{"Argon (Ar)", 1.6},
		{"Oxygen (O2)", 0.13} }, 0.377f, 0, 0.005f, 2) {std::cout << "Mars Planet Generated...\n";};

	~MarsPlanet() { std::cout << "Mars Planet Destroyed...\n"; };

	void showPlanetInfo() override;
};