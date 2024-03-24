#pragma once

#include <iostream>
#include <string>
#include <vector>

class AsteroidCluster {
public:
	const std::string name; // Example: "Kuiper Belt"
	const std::string whoseOrbitOn; // Example: "Sun"
	const int diameter; // Example: 200'000 KM
	const std::vector<std::string> asteroidType; // Example: { "M-type", "C-type" }

	AsteroidCluster(const std::string n, const std::string orbit, const int d, const std::vector<std::string> type) :
		name(n), whoseOrbitOn(orbit), diameter(d), asteroidType(type) { std::cout << name + " Asteroid Cluster generated..\n"; };
};