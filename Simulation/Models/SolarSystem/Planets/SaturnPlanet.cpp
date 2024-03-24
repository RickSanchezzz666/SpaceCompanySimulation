#include "SaturnPlanet.hpp"

#include <iostream>

using std::cout;

void SaturnPlanet::showPlanetInfo() {
	cout << "Saturn Planet Properties:";
	cout << "\n   Mass (KG): " << _mass << " KG";
	cout << "\n   Radius (KM): " << _radius << " KM";
	cout << "\n   Day Duration (MIN): " << _dayDuration << " hours";
	cout << "\n   Area (KM): " << _area << " KM^2";
	cout << "\n   Orbital Period (EarthDay): " << _orbitalPeriod << " Earth's Day";
	cout << "\n   Distance to Star (AU): " << _distanceToStar << " AU";
	cout << "\n   Max Surface Temperature (K): " << _maxTemperature << " K";
	cout << "\n   Min Surface Temperature (K): " << _minTemperature << " K";
	cout << "\n   Atmosphere (BOOL): " << _atmosphere;
	if (_atmosphere)
		cout << "\n   Atmosphere Composition ( {Element: Content%} ): ";
	for (auto it = _atmosphereComposition.begin(); it != _atmosphereComposition.end(); ++it) {
		cout << "\n   Element: " << it->first << " | Contains: " << it->second << "%";
	}
	cout << "\n   Gravity (EarthG): " << _gravity << " G";
	cout << "\n   Magnetic Field Strength (nT): " << _magneticFieldStrength << " nT";
	cout << "\n   Life Chance (%): " << _lifeChance << "%";
	cout << "\n   Moons Number: " << _moonsNumber << "\n";
}