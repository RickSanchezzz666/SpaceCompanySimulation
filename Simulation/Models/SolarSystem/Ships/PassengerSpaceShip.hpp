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

	void __sendShipToPlanet(SolarSystem* sol);
	void __landShipOnStation();


	void __startEngine() override;
	void __stopEngine() override { std::cout << shipSign + " stopped engine...\n"; }
	
	void __setSpaceShipsStatus(SpaceShipStatus status) override { this->spaceShipStatus = status; }

public:
	PassengerSpaceShip(int id) : SpaceShipAbstract(SpaceShipStatus::AVAILABLE, SpaceShipType::PASSENGER, 8, id) { std::cout << shipSign + " generated...\n"; }

	~PassengerSpaceShip() { std::cout << shipSign + " destroyed...\n"; }

	void launchShip(std::atomic<short>& astroNum, SolarSystem* sol) override;

};