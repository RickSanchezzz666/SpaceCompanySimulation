#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class SaturnPlanet : public PlanetAbstract {
public:
	SaturnPlanet(std::string name, long double mass, float radius, float day, long double area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, std::vector<std::string> moons, int id, bool belt, AsteroidCluster* cluster, std::string type) : PlanetAbstract(name, mass, radius, day,
			area, period, distance, maxTemperature, minTemperature, atmosphere, atmosphereComposition,
			gravity, magneticField, lifeChance, moonsNum, moons, id, belt, cluster, type) {};

	SaturnPlanet() : PlanetAbstract("Saturn", 5.6834E26L, 58232.0f, 10.656f, 4.27E10L, 10759.22f, 9.58f, 134, 84, true, {
		{"Hydrogen (H2)", 96.3}, {"Helium (He)", 3.25} 
		}, 1.065f, 20000, 0.01f, 82, {
		"Mimas", "Enceladus", "Tethys", "Dione", "Rhea", "Titan", "Hyperion", "Iapetus",
		"Phoebe", "Janus", "Epimetheus", "Helene", "Telesto", "Calypso", "Atlas",
		"Prometheus", "Pandora", "Pan", "Ymir", "Paaliaq", "Tarvos", "Ijiraq", "Suttungr",
		"Kiviuq", "Mundilfari", "Albiorix", "Skathi", "Siarnaq", "Thrymr", "Narvi",
		"Methone", "Pallene", "Daphnis", "Aegir", "Bebhionn", "Beli", "Bergelmir",
		"Bestla", "Farbauti", "Fenrir", "Fornjot", "Greip", "Hati", "Hyrrokkin",
		"Jarnsaxa", "Kari", "Loge", "Skoll", "Surtur", "Anthe", "Aegaeon" }, 5, true, new AsteroidCluster("Saturn's Rings", "Saturn", 300'000, {"C-type", "D-type"}), "Class I gas giant") {}
};