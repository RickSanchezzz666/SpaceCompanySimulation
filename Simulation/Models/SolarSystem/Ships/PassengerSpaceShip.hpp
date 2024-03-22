#pragma once
#include "SpaceShipAbstract.hpp"
#include "SpaceShipStatus.hpp"
#include "SpaceShipType.hpp"

#include <iostream>
#include <string>
#include <atomic>

class PassengerSpaceShip : public SpaceShipAbstract {
private:
	const std::string shipSign = ">Passenger Ship (id: " + std::to_string(this->shipId) + ")";

	std::atomic<int> __currPassengersAmount = 0;

	void __getPassengersOnBoard(const int passengersNum);
	void __removePassengersFromBoard();
	void __touristsAction(int tObject);

	void __sendShipToObject(PlanetAbstract* planet) override;
	void __sendShipToObject(StarsAbstract* sun) override;
	void __sendShipToEarth(PlanetAbstract* planet) override;
	void __sendShipToEarth(StarsAbstract* sun) override;
	void __landShipOnStation() override;

	void __startEngine() override;
	void __stopEngine() override { std::cout << shipSign + " stopped engine...\n"; }
	
	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) { std::cout << shipSign + " generated...\n"; }

	~PassengerSpaceShip() { std::cout << shipSign + " destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;

};