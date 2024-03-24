#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class NeptunePlanet : public PlanetAbstract {
private:
	std::vector<std::string> __moons = { "Triton", "Nereid", "Naiad", "Thalassa", "Despina", "Galatea", "Larissa", "Proteus",
		"Halimede", "Psamathe", "Sao", "Laomedeia", "Neso" };

public:
	NeptunePlanet(std::string name, long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time, std::vector<std::string> moons, int id) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, time, moons, id) { std::cout << "Neptune Planet Generated...\n"; };

	NeptunePlanet() : PlanetAbstract("Neptune", 1.02413E26L, 24622.0f, 16.11f, 7'618'271'000'000, 60190.0f, 30.05f, 72, 46, true, { 
		{"Hydrogen (H2)", 80}, {"Helium (He)", 19}, {"Methane (CH4)", 1.5} 
		}, 1.14f, 7200, 0.001f, 14, 800, __moons, 7) { std::cout << "Neptune Planet Generated...\n"; }

	~NeptunePlanet() { std::cout << "Neptune Planet Destroyed...\n"; };

	void showPlanetInfo() override;
};