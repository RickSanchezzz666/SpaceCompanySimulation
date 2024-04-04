#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class MercuryPlanet : public PlanetAbstract {
public:
	MercuryPlanet() : PlanetAbstract("Mercury", 3E23L, 2439.7f, 59.f, 74'800'000, 87.969f, 0.4f, 700, 90, false, {}, 0.378f, 300, .00005f, 0, {}, 1, false, "Metal-rich") {};
};