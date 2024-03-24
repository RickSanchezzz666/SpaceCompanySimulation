#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class JupiterPlanet : public PlanetAbstract {
public:
	JupiterPlanet(std::string name, long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time, std::vector<std::string> moons, int id, bool belt, AsteroidCluster* cluster) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, time, moons, id, belt, cluster) { std::cout << "Jupiter Planet Generated...\n"; };

	JupiterPlanet() : PlanetAbstract("Jupiter", 1.898E27L, 69911.0f, 9.925f, 61'420'000'000, 4332.6f, 5.20f, 165, 110, true, { 
		{"Hydrogen (H2)", 90}, {"Helium (He)", 10} 
		}, 2.528f, 42000, 0.01f, 72, 75, { "Metis", "Adrastea", "Amalthea", "Thebe", "Io", "Europa", "Ganymede",
		"Callisto", "Themisto", "Leda", "Himalia", "Lysithea", "Elara", "Dia", "Carpo", "Valetudo", "Euporie",
		"Orthosie", "Euanthe", "Thyone", "Harpalyke", "Hermippe", "Praxidike", "Isonoe", "Mneme", "Helike",
		"Ananke", "Herse", "Aitne", "Kale", "Taygete", "Chaldene", "Eurynome", "Autonoe", "Sponde", "Pasithee",
		"Megaclite", "Sinope", "Callirrhoe", "Aoede", "Kalyke", "Kore", "Cyllene", "Eukelade", "Pasiphae", "Hegemone",
		"Arche", "Iocaste", "Erinome", "Harmony", "Eupheme", "Thelxinoe", "Eirene", "Philophrosyne", }, 4, true, new AsteroidCluster("Jupiter's Belt", "Jupiter", 175'000, {"C-type", "D-type"})) { std::cout << "Jupiter Planet Generated...\n"; }

	~JupiterPlanet() { std::cout << "Jupiter Planet Destroyed...\n"; };

	void showPlanetInfo() override;
};