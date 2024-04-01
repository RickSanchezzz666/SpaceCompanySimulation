#include "EarthStation.hpp"

#include <iostream>
#include <mutex>

std::mutex mtx;

int EarthStation::getAstronautsNumber() { return __astronautsNumOnTheStation.load(std::memory_order_relaxed); }

bool EarthStation::__checkIfShipIsAvailable(const int shipId) {
    return (__findShipById(shipId)->spaceShipType != SpaceShipType::MINING
        ? (__findShipById(shipId)->spaceShipStatus == SpaceShipStatus::AVAILABLE || __findShipById(shipId)->spaceShipStatus == SpaceShipStatus::ON_STATION)
        : ((__findShipById(shipId)->spaceShipStatus == SpaceShipStatus::AVAILABLE || __findShipById(shipId)->spaceShipStatus == SpaceShipStatus::ON_STATION) && !solarSystem->isExploredClustersEmpty()));
}

bool EarthStation::checkIfShipIsAvailable(const int shipId) {
    return (__checkIfShipIsAvailable(shipId) && (getAstronautsNumber() - __findShipById(shipId)->requiredAstronautsNumber) >= 0);
}

SpaceShipAbstract* EarthStation::__findShipById(const int shipId) {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& ship : __everyShip) {
        if (ship->shipId == shipId) {
            return ship;
        }
    }
    return nullptr;
}

SpaceShipStatus EarthStation::__getShipStatus(const int shipId) {
    return __findShipById(shipId)->spaceShipStatus;

}

void EarthStation::__setSpaceShipsStatus(const int shipId, const SpaceShipStatus status) {
    SpaceShipAbstract* shipToChange = __findShipById(shipId);
    
    if (shipToChange != nullptr) shipToChange->spaceShipStatus = status;
}

void EarthStation::__getPaymentFromTheShip(const int payment) {
    balance->updateBalance(payment);
    std::cout << "\nCurrent Station Balance: " + std::to_string(balance->getBalance()) + " $\n";
}

SpaceShipType EarthStation::__getShipType(const int shipId) { return __findShipById(shipId)->spaceShipType; }

void EarthStation::launchSpaceShip(const int shipId) {
    mtx.lock();
    if (shipId >= launchThreads.size()) {
        launchThreads.resize(shipId + 1, nullptr);
    }
    mtx.unlock();

    if (!__checkIfShipIsAvailable(shipId)) return;

    mtx.lock();
    if (launchThreads[shipId] != nullptr) {
        delete launchThreads[shipId];
        launchThreads[shipId] = nullptr;
    }
    mtx.unlock();

    launchThreads[shipId] = new Thread();
    switch (shipId) {
    case 0:
        launchThreads[shipId]->createThread([&]() { 
            int payment = __everyShip[0]->launchShip(__astronautsNumOnTheStation, solarSystem);
            __getPaymentFromTheShip(payment);
        });
    case 1:
        launchThreads[shipId]->createThread([&]() { 
            int payment = __everyShip[1]->launchShip(__astronautsNumOnTheStation, solarSystem); 
            __getPaymentFromTheShip(payment);
            });
    case 2:
        launchThreads[shipId]->createThread([&]() {
            int payment = __everyShip[2]->launchShip(__astronautsNumOnTheStation, solarSystem);
            __getPaymentFromTheShip(payment);
            });
    case 3:
        launchThreads[shipId]->createThread([&]() {
            int payment = __everyShip[3]->launchShip(__astronautsNumOnTheStation, solarSystem);
            __getPaymentFromTheShip(payment);
            });
    case 4:
        launchThreads[shipId]->createThread([&]() {
            int payment = __everyShip[4]->launchShip(__astronautsNumOnTheStation, solarSystem);
            __getPaymentFromTheShip(payment);
            });
    case 5:
        launchThreads[shipId]->createThread([&]() {
            int payment = __everyShip[5]->launchShip(__astronautsNumOnTheStation, solarSystem);
            __getPaymentFromTheShip(payment);
            });
    default:
        return;
    }
}

void EarthStation::displayAvailableSpaceShips() {
    std::string infoString = "";
    infoString += "\nAvailable ships: ";
    for (auto& ship : __everyShip) {
        if (__checkIfShipIsAvailable(ship->shipId)) {
            infoString += "\nShip Id: " + std::to_string(ship->shipId) + "; Ship Type: " + (ship->spaceShipType == SpaceShipType::EXPLORER ? "Explorer" :
                (ship->spaceShipType == SpaceShipType::MINING ? "Mining" :
                    (ship->spaceShipType == SpaceShipType::PASSENGER ? "Passenger" : "None")));
        }
    }
    infoString += "\n";
    std::cout << infoString;
}


void EarthStation::displayEveryShip() {
    std::string infoString = "";
    infoString += "\nEvery Ship that Station own: ";
    if (__everyShip.empty()) infoString += "None!\n";
    else {
        for (auto& ship : __everyShip) {
            infoString += "\nShip Id: " + std::to_string(ship->shipId) + "; Ship Type: " + (ship->spaceShipType == SpaceShipType::EXPLORER ? "Explorer" :
                (ship->spaceShipType == SpaceShipType::MINING ? "Mining" :
                    (ship->spaceShipType == SpaceShipType::PASSENGER ? "Passenger" : "None")));
        }
    }
    infoString += "\n";
    std::cout << infoString;
}