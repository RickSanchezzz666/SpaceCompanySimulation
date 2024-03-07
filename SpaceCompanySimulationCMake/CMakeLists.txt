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
                                             "../Simulation/Models/Planets/PlanetAbstract.hpp"
                                             "../Simulation/Models/Ships/SpaceShipAbstract.hpp"
                                             "../Simulation/Models/Ships/PassengerSpaceShip.hpp"
                                             "../Simulation/Models/Ships/PassengerSpaceShip.cpp"
                                             "../Simulation/Models/Ships/MiningSpaceShip.hpp"
                                             "../Simulation/Models/Ships/MiningSpaceShip.cpp"
                                             "../Simulation/Models/Ships/ExplorerSpaceShip.hpp"
                                             "../Simulation/Models/Ships/ExplorerSpaceShip.cpp"
                                             "../Simulation/Models/Planets/MercuryPlanet.hpp"
                                             "../Simulation/Models/Planets/MercuryPlanet.cpp"
                                             "../Simulation/Models/Planets/VenusPlanet.hpp"
                                             "../Simulation/Models/Planets/VenusPlanet.cpp"
                                             "../Simulation/Models/Planets/MarsPlanet.hpp"
                                             "../Simulation/Models/Planets/MarsPlanet.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpaceCompanySimulationCMake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
