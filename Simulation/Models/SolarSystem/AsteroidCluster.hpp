#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>

enum AsteroidStatus {
	UNEXPLORED,
	EXPLORED
};

class AsteroidCluster {
private:
	std::unordered_map<std::string, std::vector<std::tuple<std::string, int>>> asteroidTypes = {
		{"C-type", {{std::make_tuple("Silicon (Si)", 45), std::make_tuple("Oxygen (O)", 25),
		std::make_tuple("Iron (Fe)", 15), std::make_tuple("Magnesium (Mg)", 10),
		std::make_tuple("Aluminum (Al)", 5)}}},

		{"S-type", {{std::make_tuple("Silicon (Si)", 40), std::make_tuple("Oxygen (O)", 25),
		std::make_tuple("Nickel (Ni)", 15), std::make_tuple("Iron (Fe)", 10),
		std::make_tuple("Magnesium (Mg)", 5)}}},

		{"M-type", {{std::make_tuple("Iron (Fe)", 85), std::make_tuple("Nickel (Ni)", 10),
		std::make_tuple("Cobalt (Co)", 5)}}},

		{"S-type", {{std::make_tuple("Silicon (Si)", 30), std::make_tuple("Oxygen (O)", 25),
		std::make_tuple("Carbon (C)", 15), std::make_tuple("Iron (Fe)", 13),
		std::make_tuple("Magnesium (Mg)", 12), std::make_tuple("Titanium (Ti)", 10)}}},
	};


	void __asteroidComponents(const std::vector<std::string> asteroidType) {
		for (auto& type : asteroidType) {
			asteroidComponents.push_back(asteroidTypes[type]);
		}
	}

public:
	const std::string name; // Example: "Kuiper Belt"
	const std::string whoseOrbitOn; // Example: "Sun"
	const int diameter; // Example: 200'000 KM
	const std::vector<std::string> asteroidType; // Example: { "M-type", "C-type" }
	AsteroidStatus clusterStatus = AsteroidStatus::UNEXPLORED;
	std::vector<std::vector<std::tuple<std::string, int>>> asteroidComponents;

	std::vector<std::vector<std::tuple<std::string, int>>> getAsteroidComponents() const { return asteroidComponents; }

	AsteroidCluster(const std::string n, const std::string orbit, const int d, const std::vector<std::string> type) :
		name(n), whoseOrbitOn(orbit), diameter(d), asteroidType(type) { 
		__asteroidComponents(type);
		std::cout << name + " Asteroid Cluster generated..\n"; 
	};
};