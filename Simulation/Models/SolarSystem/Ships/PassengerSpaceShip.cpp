#include "PassengerSpaceShip.hpp"

void PassengerSpaceShip::__startEngine() {
	for (int i = 3; i >= 0; --i) {
		printMessage(shipSign + " is launching in: " + std::to_string(i) + "\n");
		threadSleep(1);
	}
	printMessage(shipSign + " started engine...\n");
}

void PassengerSpaceShip::__getPassengersOnBoard(const int passengersNum) {
	__currPassengersAmount.fetch_add(passengersNum, std::memory_order_relaxed);
	printMessage(shipSign + " boarded " + std::to_string(passengersNum) + " passengers..\n");
}

void PassengerSpaceShip::__removePassengersFromBoard() {
	printMessage(shipSign + " " + std::to_string(__currPassengersAmount) + " passengers left a board..\n");
}

void PassengerSpaceShip::__doTourism(SolarSystem* sol, int objectId) {
	__touristsAction(sol, objectId);
	threadSleep(2);
	bool againSwitch = Random::getRandomNumber(0, 1);
	if (againSwitch) {
		printMessage(shipSign + " getting ready to come back to Earth..\n");
		threadSleep(2);
		return __endTourism(sol, objectId);
	}
	else {
		int targetObject = Random::getRandomNumber(0, sol->planets.size());
		for (auto& obj: __objectsVisited) {
			if (obj.objName == (targetObject == 0 ? sol->star->name : __getPlanet(sol, targetObject - 1)->_name)) {
				printMessage(shipSign + " passengers is tired. Getting ready to come back to Earth..\n");
				threadSleep(1);
				return __endTourism(sol, objectId);
			}
		}
		if (targetObject == 0) {
			printMessage(shipSign + " looking for another Planet or Star to visit..\n");
			threadSleep(2);
			__sendShipToObject(sol, sol->star);
			__objectsVisited.push_back(VisitedObject(sol->star->name));
			__doTourism(sol, sol->star->_id);
		}
		else {
			printMessage(shipSign + " looking for another Planet or Star to visit..\n");
			threadSleep(2);
			PlanetAbstract* newPlanet = __getPlanet(sol, targetObject - 1);
			__sendShipToObject(sol, newPlanet);
			__objectsVisited.push_back(VisitedObject(newPlanet->_name));
			__doTourism(sol, newPlanet->_id);
		}
	}
}

void PassengerSpaceShip::__endTourism(SolarSystem* sol, int objectId) {
	if (currentStatus == ShipCurrentStatus::INFLIGHT) {
		changeShipStatus(ShipCurrentStatus::LANDING);
		if (objectId == 0) { return __sendShipToEarth(sol, sol->star); }
		else { return __sendShipToEarth(sol, __getPlanet(sol, objectId - 1)); }
	}
}

void PassengerSpaceShip::__concludeTourism() {
	threadSleep(2);
	std::cout << "\nResults of expedition of Passenger Ship(id: " + std::to_string(this->shipId) + "):\n";
	std::cout << "Visited objects: ";
	if (__objectsVisited.size() == 0) std::cout << "None!.\n";
	else {
		std::cout << "Earth";
		for (int i = 0; i < __objectsVisited.size(); ++i) {
			std::cout << " --> " + __objectsVisited[i].objName;
		}
		std::cout << " --> Earth.\n";
	}
}


void PassengerSpaceShip::__touristsAction(SolarSystem* sol, int objectId) {
	int randomNum = -1;
	bool asteroidEvent = false;
	if (objectId == 0) {
		randomNum = Random::getRandomNumber(0, 4);
		if (!sol->isExploredClustersEmpty()) asteroidEvent = true;
	}
	else {
		randomNum = Random::getRandomNumber(5, 9);
		if (__getPlanet(sol, objectId - 1)->getAsteroidBeltStatus() == true && __getPlanet(sol, objectId - 1)->asteroidBelt->clusterStatus == AsteroidStatus::EXPLORED) asteroidEvent = true;
	}
	threadSleep(2);
	switch (randomNum)
	{
	case 0:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Astronomical observations, photography, analysis..\n");
		break;
	case 1:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Studying space debris, its impact..\n");
		break;
	case 2:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Gravity field analysis, research..\n");
		break;
	case 3:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Leisure time, relaxation, meditation, stargazing..\n");
		break;
	case 4:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Astronavigation, star charts, orientation..\n");
		break;
	case 5:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Touring orbit, learning..\n");
		break;
	case 6:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Observing cosmic phenomena..\n");
		break;
	case 7:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Drone flights, mapping..\n");
		break;
	case 8:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Planetary surface reconnaissance, soil analysis..\n");
		break;
	case 9:
		printMessage(shipSign + " TOURIST'S RADIO: " + "Experiment preparation and execution training..\n");
		break;
	default:
		printMessage(shipSign + " TOURIST'S RADIO: " + "BAD CONNECTION...\n");
		break;
	}

	threadSleep(2);

	if (asteroidEvent) {
		randomNum = Random::getRandomNumber(1, 4);

		switch (randomNum) {
		case 1:
			printMessage(shipSign + " TOURIST'S RADIO: " + "Scanning asteroid fields for potential resources..\n");
			break;
		case 2:
			printMessage(shipSign + " TOURIST'S RADIO: " + "Navigating through asteroid belts, avoiding collisions..\n");
			break;
		case 3:
			printMessage(shipSign + " TOURIST'S RADIO: " + "Studying asteroid composition..\n");
			break;
		case 4:
			printMessage(shipSign + " TOURIST'S RADIO: " + "Observing asteroid impacts, studying crater formations..\n");
			break;
		default:
			printMessage(shipSign + " TOURIST'S RADIO: " + "BAD CONNECTION...\n");
			break;
		}
	}
}

void PassengerSpaceShip::__sendShipToObject(SolarSystem* sol, PlanetAbstract* planet) {
	threadSleep(2);
	printMessage(shipSign + " route is set with the goal of reaching " + planet->_name + "..\n");
	threadSleep(5);
	if (currentStatus == ShipCurrentStatus::STARTING) {
		printMessage(shipSign + " left Earth's atmosphere..\n");
		threadSleep(2);
	}
	printMessage(shipSign + " is currently heading to " + planet->_name + "..\n");
	if (currentStatus == ShipCurrentStatus::STARTING) threadSleep(planet->timeFromEarthToPlanet);
	else threadSleep(__calculateTimeForFlight(sol, __objectsVisited[__objectsVisited.size() - 1].objName, planet->_name));
	changeShipStatus(ShipCurrentStatus::INFLIGHT);
	printMessage(shipSign + " reached " + planet->_name + "'s orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " is currently orbiting " + planet->_name + "..\n");
}

void PassengerSpaceShip::__sendShipToObject(SolarSystem* sol, StarsAbstract* sun) {
	threadSleep(2);
	printMessage(shipSign + " route is set with the goal of reaching " + sun->name + "..\n");
	threadSleep(5);
	if (currentStatus == ShipCurrentStatus::STARTING) {
		printMessage(shipSign + " left Earth's atmosphere..\n");
		threadSleep(2);
	}
	printMessage(shipSign + " is currently heading to " + sun->name + "..\n");
	if (currentStatus == ShipCurrentStatus::STARTING) threadSleep(sun->timeFromEarthToStar);
	else threadSleep(__calculateTimeForFlight(sol, __objectsVisited[__objectsVisited.size() - 1].objName, sun->name));
	changeShipStatus(ShipCurrentStatus::INFLIGHT);
	printMessage(shipSign + " reached " + sun->name + "'s orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " is currently orbiting " + sun->name + "..\n");
}

void PassengerSpaceShip::__sendShipToEarth(SolarSystem* sol, PlanetAbstract* planet) {
	threadSleep(5);
	printMessage(shipSign + " started heading back to Earth from " + planet->_name + "..\n");
	threadSleep(planet->timeFromEarthToPlanet);
	printMessage(shipSign + " is on Earth's orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " began to enter Earth's atmosphere..\n");
}

void PassengerSpaceShip::__sendShipToEarth(SolarSystem* sol, StarsAbstract* star) {
	threadSleep(5);
	printMessage(shipSign + " started heading back to Earth from " + star->name + "..\n");
	threadSleep(star->timeFromEarthToStar);
	printMessage(shipSign + " is on Earth's orbit..\n");
	threadSleep(2);
	printMessage(shipSign + " began to enter Earth's atmosphere..\n");
}

void PassengerSpaceShip::__landShipOnStation() {
	changeShipStatus(ShipCurrentStatus::LANDING);
	threadSleep(2);
	printMessage(shipSign + " is getting ready to land on Earth's Station..\n");
	threadSleep(3);
	printMessage(shipSign + " successfully landed on Earth's Station..\n");
	this->__stopEngine();
}

int PassengerSpaceShip::__calculateRevenue() {
	int multiplier = 1;
	if (shipType == PassengerShipType::ECONOM) multiplier = 1;
	else if (shipType == PassengerShipType::BUSSINESS) multiplier = 2;
	else if (shipType == PassengerShipType::PREMIUM) multiplier = 4;

	int revenue = (1000 * __currPassengersAmount * multiplier * __objectsVisited.size());
	std::cout << "Passenger Ship Revenue: ";
	std::cout << "\nRevenue from Tourism: " + std::to_string(revenue) + " $\n";
	return revenue;
}

int PassengerSpaceShip::launchShip(std::atomic<short>& astroNum, SolarSystem* sol) {
	__setSpaceShipsStatus(SpaceShipStatus::BUSY);
	__decreaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	printMessage(shipSign + " is preparing for a flight..\n", true);
	__getPassengersOnBoard(Random::getRandomNumber(10, 33));
	threadSleep(1);
	printMessage(shipSign + " is launching..\n");
	this->__startEngine();
	changeShipStatus(ShipCurrentStatus::STARTING);
	int targetObject = Random::getRandomNumber(0, sol->planets.size());
	//0 - Sun
	//other - Planets
	if (targetObject == 0) {
		__sendShipToObject(sol, sol->star);
		__objectsVisited.push_back(VisitedObject(sol->star->name));
		__doTourism(sol, sol->star->_id);
	}
	else {
		PlanetAbstract* planet = __getRandomPlanet(sol);
		__sendShipToObject(sol, planet);
		__objectsVisited.push_back(VisitedObject(planet->_name));
		__doTourism(sol, planet->_id);
	}
	__landShipOnStation();
	__removePassengersFromBoard();
	__concludeTourism();
	int revenue = __calculateRevenue();
	changeShipStatus(ShipCurrentStatus::LANDED);
	__setSpaceShipsStatus(SpaceShipStatus::AVAILABLE);
	__objectsVisited.clear();
	__currPassengersAmount = 0;
	__increaseAstronautsNumber(astroNum, this->requiredAstronautsNumber);
	return revenue;
}
