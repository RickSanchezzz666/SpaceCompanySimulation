#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>
#include <atomic>

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	const std::string shipSign = " >Passenger Ship (id: " + std::to_string(this->shipId) + ")";

	std::atomic<int> __currPassengersAmount = 0;

	std::vector<VisitedObject> __objectsVisited;

	void __doTourism(SolarSystem* sol, int objectId);
	void __endTourism(SolarSystem* sol, int objectId);
	
	void __concludeTourism();

	void __getPassengersOnBoard(const int passengersNum);
	void __removePassengersFromBoard();
	void __touristsAction(SolarSystem* sol, int objectId);

	void __sendShipToObject(SolarSystem* sol, PlanetAbstract* planet) override;
	void __sendShipToObject(SolarSystem* sol, StarsAbstract* sun) override;
	void __sendShipToEarth(SolarSystem* sol, PlanetAbstract* planet) override;
	void __sendShipToEarth(SolarSystem* sol, StarsAbstract* sun) override;
	void __landShipOnStation() override;

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }
	
	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) {}

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;

};