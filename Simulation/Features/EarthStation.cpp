#include "EarthStation.hpp"

#include <iostream>

int EarthStation::getAstronautsNumber() {
    return __astronautsNumOnTheStation;
}

void EarthStation::__addAstronautsNumber(int num) {
    __astronautsNumOnTheStation += num;
}

bool EarthStation::__decreaseAstronautsNumber(int num) {
    int currentNum = getAstronautsNumber();
    if ((currentNum - num) < 0) return false;
    else __astronautsNumOnTheStation -= num;
}

void EarthStation::__makeShipInFlight(const int shipId) {
    if (__checkIfShipIsAvailable(shipId)) {
        SpaceShipAbstract* shipToTransfer = __findShipById(shipId);
        int index;
        for (index = 0; index < __availableSpaceShips.size(); ++index) if (__availableSpaceShips[index]->shipId == shipId) break;
        __availableSpaceShips.erase(__availableSpaceShips.begin() + index);
        __spaceShipsInFlight.push_back(shipToTransfer);
        __setSpaceShipsStatus(shipToTransfer->shipId, SpaceShipStatus::BUSY);
    }
}

void EarthStation::__makeShipAvailable(const int shipId) {
    if (!__checkIfShipIsAvailable(shipId)) {
        SpaceShipAbstract* shipToTransfer = __findShipById(shipId);
        int index;
        for (index = 0; index < __spaceShipsInFlight.size(); ++index) if (__spaceShipsInFlight[index]->shipId == shipId) break;
        __spaceShipsInFlight.erase(__spaceShipsInFlight.begin() + index);
        __availableSpaceShips.push_back(shipToTransfer);
        __setSpaceShipsStatus(shipToTransfer->shipId, SpaceShipStatus::AVAILABLE);
    }
}

bool EarthStation::__checkIfShipIsAvailable(const int shipId) {
    return __findShipById(shipId)->spaceShipStatus == SpaceShipStatus::AVAILABLE;
}

SpaceShipAbstract* EarthStation::__findShipById(const int shipId) {
    for (auto& ship : __everyShip) {
        if (ship->shipId == shipId) {
            return ship;
        }
    }
    return nullptr;
}

void EarthStation::__setSpaceShipsStatus(const int shipId, SpaceShipStatus status) {
    SpaceShipAbstract* shipToChange = __findShipById(shipId);
    
    if (shipToChange != nullptr) shipToChange->spaceShipStatus = status;
}


void EarthStation::launchSpaceShip(const int shipId) {
    if (shipId >= launchThreads.size()) {
        launchThreads.resize(shipId + 1, nullptr);
    }

    if (launchThreads[shipId] != nullptr) {
        delete launchThreads[shipId];
        launchThreads[shipId] = nullptr;
    }

    launchThreads[shipId] = new Thread();
    launchThreads[shipId]->createThread([&]() { __availableSpaceShips[shipId]->launchShip(); });
}
