#include "SunStar.hpp"

#include <iostream>

using std::cout;

void SunStar::showStarInfo() {
	std::string infoString = "";
	infoString += "Sun Star Properties:";
	infoString += "\n   Mass (KG): " + std::to_string(_mass) + " KG";
	infoString += "\n   Radius (KM): " + std::to_string(_radius) + " KM";
	infoString += "\n   Area (KM): " + std::to_string(_area) + " KM^2";
	infoString += "\n   Age (Billion Years): " + std::to_string(_age) + "B Years";
	infoString += "\n   Surface Temperature (K): " + std::to_string(_surfaceTemperature) + " K";
	infoString += "\n   Star's Type: " + _starType;
	infoString += "\n   Star's Luminosity: " + _luminosity;
	infoString += "\n   Star's Full Spectral Class: " + _fullSpectralClass;
	infoString += "\n   Absolute Magnitued: " + std::to_string(_absoluteMagnitude);
	infoString += "\n   Distance to the Center of the Galaxy (LY): " + std::to_string(_distanceToCenterOfGalaxy) + " Light Years\n";
	std::cout << infoString;
}