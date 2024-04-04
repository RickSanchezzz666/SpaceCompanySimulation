#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class NeptunePlanet : public PlanetAbstract {
public:
	NeptunePlanet() : PlanetAbstract("Neptune", 1.02413E26L, 24622.0f, 16.11f, 7.618E9L, 60190.0f, 30.05f, 72, 46, true, {
		{"Hydrogen (H2)", 80}, {"Helium (He)", 19}, {"Methane (CH4)", 1.5} 
		}, 1.14f, 7200, 0.001f, 14, { "Triton", "Nereid", "Naiad", "Thalassa", "Despina", "Galatea", "Larissa", "Proteus",
		"Halimede", "Psamathe", "Sao", "Laomedeia", "Neso" }, 7, true, new AsteroidCluster("Neptune's Belt", "Neptune", 39'000, {"C-type"}), "Class I gas giant") {}
};