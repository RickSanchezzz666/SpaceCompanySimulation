#include "MiningSpaceShip.hpp"

void MiningSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		printMessage(shipSign + " is launching in: " + std::to_string(i) + "\n");
		threadSleep(1);
	}
	printMessage(shipSign + " started engine...\n");
}

void MiningSpaceShip::__sendShipToCluster(SolarSystem* sol, AsteroidCluster* cluster) {
	threadSleep(2);
	printMessage(shipSign + " route is set with the goal of reaching " + cluster->name + " on " + cluster->whoseOrbitOn + "'s orbit..\n");
	threadSleep(5);
	if (currentStatus == ShipCurrentStatus::STARTING) {
		printMessage(shipSign + " left Earth's atmosphere..\n");
		threadSleep(2);
	}
	printMessage(shipSign + " is currently heading to " + cluster->name + "..\n");
	if (currentStatus == ShipCurrentStatus::STARTING) threadSleep(__getTimeForFlight(sol, cluster->whoseOrbitOn));
	//else threadSleep(calculateTimeForFlight(sol, __objectsVisited[__objectsVisited.size() - 1], planet->_name));
	changeShipStatus(ShipCurrentStatus::INFLIGHT);
	printMessage(shipSign + " reached " + cluster->name + "'s orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " successfully flew into " + cluster->name + "..\n");
}

void MiningSpaceShip::__sendShipToEarth(SolarSystem* sol, AsteroidCluster* cluster) {
	threadSleep(5);
	printMessage(shipSign + " started heading back to Earth from " + cluster->name + " on " + cluster->whoseOrbitOn + "'s orbit..\n");
	threadSleep(__getTimeForFlight(sol, cluster->whoseOrbitOn));
	printMessage(shipSign + " is on Earth's orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " began to enter Earth's atmosphere..\n");
}

std::string MiningSpaceShip::__getElementFromAsteroid(const int& chance, std::vector<std::tuple<std::string, int>>& components) {
	int cumulativePercentage = 0;
	for (const auto& element : components) {
		cumulativePercentage += std::get<1>(element);
		if (chance <= cumulativePercentage) {
			return std::get<0>(element);
		}
	}
	return std::get<0>(components.back());
}

void MiningSpaceShip::__miningActions(SolarSystem* sol, AsteroidCluster* cluster) {
	std::vector<std::vector<std::tuple<std::string, int>>> components = cluster->getAsteroidComponents();
	do {
		threadSleep(1);
		printMessage(shipSign + " number of Limpets Drones: " + std::to_string(__numberOfLimpetDrones) + "..\n");
		threadSleep(1);
		printMessage(shipSign + " scanning for potentinal Asteroid for Mining..\n");
		threadSleep(2);
		int asteroidType = Random::getRandomNumber(0, components.size() - 1);

		printMessage(shipSign + " Found potentinal " + cluster->asteroidType[asteroidType] + " Asteroid for Mining!.\n");
		threadSleep(1);
		printMessage(shipSign + " launched Limpet Drone in Asteroid..\n");
		threadSleep(3);
		printMessage(shipSign + " MINING RADIO: " + cluster->asteroidType[asteroidType] + " Asteroid successfully blown up..\n");
		threadSleep(2);
		printMessage(shipSign + " MINING RADIO: Started collecting resources..\n");
		threadSleepMilliSeconds(1500);
		for (int i = 0; i < Random::getRandomNumber(1, 3); ++i) {
			int randomChance = Random::getRandomNumber(1, 100);
			int randomAmount = Random::getRandomNumber(1, 3);
			std::string element = __getElementFromAsteroid(randomChance, components[asteroidType]);
			__minedResourses.push_back(std::make_tuple(element, randomAmount));
			printMessage(shipSign + " collected: (Element: " + element + "; Amount: " + std::to_string(randomAmount) + ")..\n");
			threadSleepMilliSeconds(500);
		}
		printMessage(shipSign + " MINING RADIO: Asteroid was successfully mined!..\n");
		threadSleep(1);
	} while (--__numberOfLimpetDrones);
}

void MiningSpaceShip::__doMining(SolarSystem* sol, AsteroidCluster* cluster) {
	threadSleep(2);
	__miningActions(sol, cluster);
	printMessage(shipSign + " number of Limpets Drones: " + std::to_string(__numberOfLimpetDrones) + "! Mining is finished!.\n");
	threadSleep(2);
	printMessage(shipSign + " leaving Asteroid cluster..\n");
	__sendShipToEarth(sol, cluster);
}


void MiningSpaceShip::__landShipOnStation() {
	changeShipStatus(ShipCurrentStatus::LANDING);
	threadSleep(2);
	printMessage(shipSign + " is getting ready to land on Earth's Station..\n");
	threadSleep(3);
	printMessage(shipSign + " successfully landed on Earth's Station..\n");
	this->__stopEngine();
}

std::unordered_map<std::string, int> MiningSpaceShip::__calculateCollectedResources() {
	std::unordered_map<std::string, int> resources;
	for (const auto& resource : __minedResourses) {
		resources[std::get<0>(resource)] += std::get<1>(resource);
	}
	return resources;
}

void MiningSpaceShip::__concludeMining() {
	threadSleep(2);
	std::cout << "\nResults of Mining expedition of Mining Ship(id: " + std::to_string(this->shipId) + "):\n";
	std::cout << "Visited objects: ";
	if (__objectsVisited.size() == 0) std::cout << "None!.\n";
	else {
		std::cout << "Earth";
		for (int i = 0; i < __objectsVisited.size(); ++i) {
			std::cout << " --> " + std::get<0>(__objectsVisited[i]);
		}
		std::cout << " --> Earth.\n";
	}
	std::cout << "Gathered resources: ";
	if (__minedResourses.size() == 0) std::cout << "None!.\n";
	else { 
		std::unordered_map<std::string, int> resources = __calculateCollectedResources();
		for (const auto& resource : resources) {
			std::cout << "\nElement: " + resource.first + "; Amount: " + std::to_string(resource.second) + ".";
		}
	}
}


void MiningSpaceShip::launchShip(std::atomic<short>& astroNum, SolarSystem* sol) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	printMessage(shipSign + " is preparing for a flight..\n", true);
	__getLimpetDrones(Random::getRandomNumber(5, 25));
	threadSleep(1);
	printMessage(shipSign + " is launching..\n");
	this->__startEngine();
	changeShipStatus(ShipCurrentStatus::STARTING);
	int targetCluster = Random::getRandomNumber(0, sol->getExploredClusters().size() - 1);
	AsteroidCluster* cluster = sol->getExploredClusters()[targetCluster];

	__sendShipToCluster(sol, cluster);
	__objectsVisited.push_back(std::make_tuple(cluster->name, cluster->whoseOrbitOn));
	__doMining(sol, cluster);

	__landShipOnStation();
	__concludeMining();
	__removeLimpetDrones();
	changeShipStatus(ShipCurrentStatus::LANDED);
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
}
