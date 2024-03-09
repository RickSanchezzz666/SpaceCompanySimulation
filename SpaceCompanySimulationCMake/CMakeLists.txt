# CMakeList.txt : CMake project for SpaceCompanySimulationCMake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SpaceCompanySimulationCMake")

# Add source to this project's executable.
add_executable (SpaceCompanySimulationCMake  "../Simulation/main.cpp"
                                             "../Simulation/Models/SolarSystem/Planets/PlanetAbstract.hpp"
                                             "../Simulation/Models/SolarSystem/Ships/SpaceShipAbstract.hpp"
                                             "../Simulation/Models/SolarSystem/Stars/StarsAbstract.hpp"
                                             "../Simulation/Models/SolarSystem/Ships/PassengerSpaceShip.hpp"
                                             "../Simulation/Models/SolarSystem/Ships/PassengerSpaceShip.cpp"
                                             "../Simulation/Models/SolarSystem/Ships/MiningSpaceShip.hpp"
                                             "../Simulation/Models/SolarSystem/Ships/MiningSpaceShip.cpp"
                                             "../Simulation/Models/SolarSystem/Ships/ExplorerSpaceShip.hpp"
                                             "../Simulation/Models/SolarSystem/Ships/ExplorerSpaceShip.cpp"
                                             "../Simulation/Models/SolarSystem/Planets/MercuryPlanet.hpp"
                                             "../Simulation/Models/SolarSystem/Planets/MercuryPlanet.cpp"
                                             "../Simulation/Models/SolarSystem/Planets/VenusPlanet.hpp"
                                             "../Simulation/Models/SolarSystem/Planets/VenusPlanet.cpp"
                                             "../Simulation/Models/SolarSystem/Planets/MarsPlanet.hpp"
                                             "../Simulation/Models/SolarSystem/Planets/MarsPlanet.cpp"
                                             "../Simulation/Models/SolarSystem/Stars/SunStar.hpp"
                                             "../Simulation/Models/SolarSystem/Stars/SunStar.cpp"
                                             "../Simulation/Models/SolarSystem/SolarSystem.hpp"
                                             "../Simulation/Models/SolarSystem/SolarSystem.cpp"
                                             "../Simulation/Models/SolarSystem/Ships/SpaceShipType.hpp"
                                             "../Simulation/Features/EarthStation.hpp"
                                             "../Simulation/Features/EarthStation.cpp"
                                             "../Simulation/Features/SpaceShipStatus.hpp"
                                             "../Threads/Thread.hpp"
                                             "../Threads/Thread.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpaceCompanySimulationCMake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
