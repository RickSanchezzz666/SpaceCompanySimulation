#pragma once 

#include <string>
#include <unordered_map>

class StarsAbstract {
protected:
    const long double _mass; // Example: 3E23L KG
    const float _radius; // Example: 2439,7 KM
    const long double _area; // Example: 78'800'000 KM^2
    const float _age; // Example: 4.6B Years
    const int _surfaceTemperature; // Example: 5772 K
    const std::string _starType; // Example: G (Yellow-Orange)
    const std::string _luminosity; // Example: V
    const std::string _fullSpectralClass; // Example: G2 V
    const float _absoluteMagnitude; // Example: 4,83
    const int _distanceToCenterOfGalaxy; // Example: 26660 LY

public:
    const int _id; // objectId
    const std::string name; // Star Name
    const int timeFromEarthToStar; // 1 million KM in - 1 sec

    StarsAbstract(long double mass, float radius, long double area, float age, int temp, std::string starType,
        std::string luminosity, std::string spectralClass, float absoluteMagnitude, int distance, std::string name, int time, int id) : 
        _mass(mass), _radius(radius), _area(area), _age(age), _surfaceTemperature(temp), _starType(starType),
        _luminosity(luminosity), _fullSpectralClass(spectralClass), _absoluteMagnitude(absoluteMagnitude), 
        _distanceToCenterOfGalaxy(distance), name(name), timeFromEarthToStar(time), _id(id) {};

    virtual void showStarInfo() = 0;
};