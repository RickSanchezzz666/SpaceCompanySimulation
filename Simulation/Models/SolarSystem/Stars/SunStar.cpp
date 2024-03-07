#include "SunStar.hpp"

#include <iostream>

using std::cout;

void SunStar::showStarInfo() {
	cout << "Sun Star Properties:";
	cout << "\n   Mass (KG): " << _mass << " KG";
	cout << "\n   Radius (KM): " << _radius << " KM";
	cout << "\n   Area (KM): " << _area << " KM^2";
	cout << "\n   Age (Billion Years): " << _age << "B Years";
	cout << "\n   Surface Temperature (K): " << _surfaceTemperature << " K";
	cout << "\n   Star's Type: " << _starType;
	cout << "\n   Star's Luminosity: " << _luminosity;
	cout << "\n   Star's Full Spectral Class: " << _fullSpectralClass;
	cout << "\n   Absolute Magnitued: " << _absoluteMagnitude;
	cout << "\n   Distance to the Center of the Galaxy (LY): " << _distanceToCenterOfGalaxy << " Light Years\n";
}

void SunStar::generateStar() {
	cout << "Sun Star is generated...\n";
}

void SunStar::destroyStar() {
	cout << "Sun Star is destroyed...\n";
}