#pragma once
#include "Models/SolarSystem/SolarSystem.hpp"
#include "Features/EarthStation.hpp"
#include "Features/Random.hpp"

#include <iostream>
#include <thread>
#include <chrono>

class Simulation : Random {
private:
	SolarSystem* solarSystem;
	EarthStation* earthStation;

	void __startSimulation();

	void __showInfo();

public:
	Simulation() {
		solarSystem = new SolarSystem();
		earthStation = new EarthStation(solarSystem);
	};

	~Simulation() {
		delete solarSystem;
		delete earthStation;
	}

	void startSimulation() {
		__showInfo();
		__startSimulation();
		std::cin.get();
	}

	
};