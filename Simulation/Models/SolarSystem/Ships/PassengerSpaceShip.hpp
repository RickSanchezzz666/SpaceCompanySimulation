#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>
#include <atomic>

enum PassengerShipType {
	ECONOM,
	BUSSINESS,
	PREMIUM
};

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	std::string shipSign;
	
	const PassengerShipType shipType;
	
	std::string shipSymbol; // E - Econom, B - Bussiness, P - Premium, U - Undefined

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

	int __calculateRevenue() override;

	void __startEngine() override;
	void __stopEngine() override { printMessage(shipSign + " stopped engine...\n"); }
	
	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id, int type) : shipType(static_cast<PassengerShipType>(type)), SpaceShipAbstract(SpaceShipStatus::ON_STATION, SpaceShipType::PASSENGER, 8, id) {
		if (shipType == PassengerShipType::ECONOM) shipSymbol = "E";
		else if (shipType == PassengerShipType::BUSSINESS) shipSymbol = "B";
		else if (shipType == PassengerShipType::PREMIUM) shipSymbol = "P";
		else shipSymbol = "U";

		shipSign = " >Passenger Ship '" + shipSymbol + "' (id: " + std::to_string(this->shipId) + ")"; 
	}

	int launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;

};