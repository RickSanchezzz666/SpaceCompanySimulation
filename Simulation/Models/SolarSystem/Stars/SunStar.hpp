#pragma once
#include "StarsAbstract.hpp"

#include <iostream>

class SunStar : public StarsAbstract {
public:
	SunStar() : StarsAbstract(1.9885E30L, 696'000, 6.09E12L, 4.6f, 5772, "G (White Yellow)", "V", "G2 V", 4.83f, 26660, "Sun", 15, 0) {};

	void showStarInfo() override;
};