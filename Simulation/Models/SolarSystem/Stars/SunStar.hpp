#pragma once
#include "StarsAbstract.hpp"

#include <iostream>

class SunStar : public StarsAbstract {
public:
	SunStar(long double mass, float radius, long double area, float age, int temp, std::string starType,
		std::string luminosity, std::string spectralClass, float absoluteMagnitude, int distance) :
		StarsAbstract(mass, radius, area, age, temp, starType, luminosity, spectralClass, absoluteMagnitude, distance) { std::cout << "Sun Star generated...\n"; };

	SunStar() : StarsAbstract(1.9885E30L, 696'000, 6.09E12L, 4.6f, 5772, "G (White Yellow)", "V", "G2 V", 4.83f, 26660) { std::cout << "Sun Star generated...\n"; };

	~SunStar() { std::cout << "Sun Star destroyed...\n"; };

	void showStarInfo() override;
};