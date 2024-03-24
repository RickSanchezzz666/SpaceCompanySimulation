#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class UranusPlanet : public PlanetAbstract {
private:
	std::vector<std::string> __moons = { "Miranda", "Ariel", "Umbriel", "Titania", "Oberon", "Cordelia", "Ophelia",
		"Bianca", "Cressida", "Desdemona", "Juliet", "Portia", "Rosalind", "Belinda", "Puck", "Caliban", "Sycorax",
		"Prospero", "Setebos", "Stephano", "Trinculo", "Francisco", "Margaret", "Ferdinand", "Perdita" };

public:
	UranusPlanet(std::string name, long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time, std::vector<std::string> moons, int id) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, time, moons, id) { std::cout << "Uranus Planet Generated...\n"; };

	UranusPlanet() : PlanetAbstract("Uranus", 8.6810E25L, 25362.0f, 17.24f, 8'115'600'000, 30685.0f, 19.22f, 76, 49, true, {
		{"Hydrogen (H2)", 82.5}, {"Helium (He)", 15.2}, {"Methane (CH4)", 2.3} 
		}, 0.886f, 7500, 0.001f, 27, 260, __moons, 6) { std::cout << "Uranus Planet Generated...\n"; }

	~UranusPlanet() { std::cout << "Uranus Planet Destroyed...\n"; };

	void showPlanetInfo() override;
};