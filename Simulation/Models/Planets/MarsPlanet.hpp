#pragma once
#include "PlanetAbstract.hpp"

class MarsPlanet : public PlanetAbstract {
public:
	MarsPlanet(long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum) : PlanetAbstract(mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum) {}

	void showPlanetInfo() override;
	void generatePlanet() override;
	void destroyPlanet() override;
};