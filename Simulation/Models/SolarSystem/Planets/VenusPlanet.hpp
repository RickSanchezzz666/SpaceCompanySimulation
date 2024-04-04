#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class VenusPlanet : public PlanetAbstract {
public:
	VenusPlanet() : PlanetAbstract("Venus", 4.867E24L, 6051.8f, 243.025f, 460'200'000, 224.7f, 0.72f, 464, 462, true, { {"Carbon Dioxide (CO2)", 96.5},
																								{"Nitrogen (N)", 3.5} }, 0.907f, 0, .0f, 0, {}, 2, false, "High metal content world") {};
};