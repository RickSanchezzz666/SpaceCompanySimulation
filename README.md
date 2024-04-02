# Space Station Company Simulation.

## Stack

In this project I have used ```C++``` mainly, along with ```CMake``` and ```Catch2``` for Unit Testing.

## About Simulation

Station have 3 types of space ships: explorer, mining and passenger. Different planets of Solar system (Asteroid clusters and Sun). Planets will have different parameters such as, mass, radius, life chance. Ships do various things such as exploring, mining and tourism. Earn as much money as you want!

## How to Configure ```Catch2```
1. Download realease from github: https://github.com/catchorg/Catch2 
or clone repository to your Main CMake Project folder.
$ git clone https://github.com/catchorg/Catch2.git
2. Then move to Catch2 directory by using "cd". Example: cd Catch2.
3. Firstly add this line in CMakeLists.txt:
```
set(CMAKE_INSTALL_PREFIX "/Path")
# (/Path - Folder you want to install Catch2)
```
4. Run - $ cmake -Bbuild -H. -DBUILD_TESTING=OFF
5. Open Visual Studio as Administrator or use "sudo" if you using UNIX system
6. Run - cmake --build build/ --target install 
7. In CMakeLists.txt add this lines:
```
find_package(Catch2 REQUIRED PATHS "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/Catch2")
# (I have my Catch2 files inside "Dependencies" folder)'
# then create your test files and include them (add_executable(TestsFiles test.cpp)) and add that:
target_link_libraries(TestsFiles Catch2::Catch2)
```
8. Inside this CMake folder create tests and run them!
