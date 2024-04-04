#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class MarsPlanet : public PlanetAbstract {
public:
	MarsPlanet() : PlanetAbstract("Mars", 6.417E23L, 3389.5f, 1.025f, 144'800'000, 687.0f, 1.52f, 35, -143, true,
		{ {"Carbon Dioxide (CO2)", 95.32},
		{"Nitrogen (N)", 2.7},
		{"Argon (Ar)", 1.6},
		{"Oxygen (O2)", 0.13} }, 0.377f, 0, 0.005f, 2, { "Phobos", "Deimos" }, 3, false, "Rocky") {
	};
};