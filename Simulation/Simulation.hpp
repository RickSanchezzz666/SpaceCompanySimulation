#pragma once
#include "Models/SolarSystem/SolarSystem.hpp"
#include "Features/EarthStation.hpp"
#include "Features/Random.hpp"
#include "../Threads/Thread.hpp"

#include <iostream>
#include <thread>
#include <chrono>

class Simulation : Random {
private:
	SolarSystem* solarSystem;
	EarthStation* earthStation;

	bool firstLaunch = true;

	void __launchShip();

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
		std::cout << "Press Enter if you want to stop simulation...\n";
		__showInfo();
		Thread* thread = new Thread();
		thread->createThread([&]() { __startSimulation(); });
		std::cin.get();
		std::cout << "\nYou have successfully earned: " + std::to_string(earthStation->balance->getBalance()) + " $\nThanks for the participation!\n";
	}

};