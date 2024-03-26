#pragma once

#include "../AsteroidCluster.hpp"

#include <string>
#include <unordered_map>
#include <vector>

class PlanetAbstract {
protected:
	const long double _mass; // Example: 3E23L KG
	const float _radius; // Example: 2439,7 KM
	const float _dayDuration; // Example: 23,59 EarthDays
	const long double _area; // Example: 3E10L KM^2
	const float _orbitalPeriod; // Example: 87,969 EarthDays
	const float _distanceToStar; // Example: 0,4 AU (Astronomical Units)
	const int _maxTemperature; // Example: 255 K
	const int _minTemperature; // Example: 32 K
	const bool _atmosphere; // Example: True
	const std::unordered_map<std::string, float> _atmosphereComposition; // Example: {"Oxygen(O)": 59,2, "Sodium(Na)": 25,2, "Hydrogen": 5,6, "Helium(H)": 10,4, "Potassium(K)": 5}
	const float _gravity; // Example: 0,38 EarthG
	const int _magneticFieldStrength; // Example: 300 nT
	const float _lifeChance; // Example: 0.1 %
	const int _moonsNumber; // Example: 2
	std::vector<std::string> _unexploredMoons; // Example: {"Deimos", "Phobos"}
	std::vector<std::string> _exploredMoons; // Example: {}
	const bool _asteroidBelt; // Example: True

public:
	const int _id; // objectId
	const std::string _name; // Planet Name
	const int timeFromEarthToPlanet; // 1 million KM in - 1 sec + min distance in KM
	AsteroidCluster* asteroidBelt = nullptr; // AsteroidCluster Object

	bool getAsteroidBeltStatus() const { return _asteroidBelt; }

	int getMoonsNum() const { return _moonsNumber; }
	std::vector<std::string> getUnexploredMoons() { return _unexploredMoons; }
	std::vector<std::string> getExploredMoons() { return _exploredMoons; }

	std::string makeMoonExplored(int index) {
		std::string moon = _unexploredMoons[index];
		_unexploredMoons.erase(_unexploredMoons.begin() + index);
		_exploredMoons.push_back(moon);
		return moon;
	}

	//no asteroid belt
	PlanetAbstract(std::string name, long double mass, float radius, float day, long double area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time, std::vector<std::string> moons, int id, bool belt) : _name(name), _mass(mass), _radius(radius),
		_dayDuration(day), _area(area), _orbitalPeriod(period),
		_distanceToStar(distance), _maxTemperature(maxTemperature), _minTemperature(minTemperature), 
		_atmosphere(atmosphere), _atmosphereComposition(atmosphereComposition), _gravity(gravity), 
		_magneticFieldStrength(magneticField), _lifeChance(lifeChance), _moonsNumber(moonsNum), timeFromEarthToPlanet(time), _unexploredMoons(moons), _id(id), _asteroidBelt(belt) {};

	//asteroid belt
	PlanetAbstract(std::string name, long double mass, float radius, float day, long double area,
		float period, float distance, int maxTemperature, int minTemperature, bool atmosphere,
		std::unordered_map<std::string, float> atmosphereComposition, float gravity,
		int magneticField, float lifeChance, int moonsNum, int time, std::vector<std::string> moons, int id, bool belt, AsteroidCluster* cluster) : _name(name), _mass(mass), _radius(radius),
		_dayDuration(day), _area(area), _orbitalPeriod(period),
		_distanceToStar(distance), _maxTemperature(maxTemperature), _minTemperature(minTemperature),
		_atmosphere(atmosphere), _atmosphereComposition(atmosphereComposition), _gravity(gravity),
		_magneticFieldStrength(magneticField), _lifeChance(lifeChance), _moonsNumber(moonsNum), timeFromEarthToPlanet(time), _unexploredMoons(moons), _id(id), _asteroidBelt(belt), asteroidBelt(cluster) {};

	virtual ~PlanetAbstract() {};

	virtual void showPlanetInfo() = 0;
};