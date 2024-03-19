#pragma once

#include <string>
#include <unordered_map>

class PlanetAbstract {
protected:
	const long double _mass; // Example: 3E23L KG
	const float _radius; // Example: 2439,7 KM
	const float _dayDuration; // Example: 23,59 EarthDays
	const long int _area; // Example: 78'800'000 KM^2
	const float _orbitalPeriod; // Example: 87,969 EarthDays
	const float _distanceToStar; // Example: 0,4 AU (Astronomical Units)
	//whoseOrbitOn
	const int _maxTemperature; // Example: 255 K
	const int _minTemperature; // Example: 32 K
	const bool _atmosphere; // Example: True
	const std::unordered_map<std::string, float> _atmosphereComposition; // Example: {"Oxygen(O)": 59,2, "Sodium(Na)": 25,2, "Hydrogen": 5,6, "Helium(H)": 10,4, "Potassium(K)": 5}
	const float _gravity; // Example: 0,38 EarthG
	const int _magneticFieldStrength; // Example: 300 nT
	const float _lifeChance; // Example: 0.1 %
	const int _moonsNumber;
	// moons
	// asteroidClusters

public:
	const std::string _name; // Planet Name
	const int timeFromEarthToPlanet; // 1 million KM in 1 Sec - 1 sec + min distance in KM

	PlanetAbstract(std::string name, long double mass, float radius, float day, long int area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time) : _name(name), _mass(mass), _radius(radius),
		_dayDuration(day), _area(area), _orbitalPeriod(period),
		_distanceToStar(distance), _maxTemperature(maxTemperature), _minTemperature(minTemperature), 
		_atmosphere(atmosphere), _atmosphereComposition(atmosphereComposition), _gravity(gravity), 
		_magneticFieldStrength(magneticField), _lifeChance(lifeChance), _moonsNumber(moonsNum), timeFromEarthToPlanet(time){};

	virtual ~PlanetAbstract() {};

	virtual void showPlanetInfo() = 0;
};