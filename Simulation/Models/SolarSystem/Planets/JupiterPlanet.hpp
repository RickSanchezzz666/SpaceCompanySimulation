#pragma once
#include "PlanetAbstract.hpp"

#include <iostream>

class JupiterPlanet : public PlanetAbstract {
public:
	JupiterPlanet() : PlanetAbstract("Jupiter", 1.898E27L, 69911.0f, 9.925f, 6.142E10L, 4332.6f, 5.20f, 165, 110, true, {
		{"Hydrogen (H2)", 90}, {"Helium (He)", 10} 
		}, 2.528f, 42000, 0.01f, 72, { "Metis", "Adrastea", "Amalthea", "Thebe", "Io", "Europa", "Ganymede",
		"Callisto", "Themisto", "Leda", "Himalia", "Lysithea", "Elara", "Dia", "Carpo", "Valetudo", "Euporie",
		"Orthosie", "Euanthe", "Thyone", "Harpalyke", "Hermippe", "Praxidike", "Isonoe", "Mneme", "Helike",
		"Ananke", "Herse", "Aitne", "Kale", "Taygete", "Chaldene", "Eurynome", "Autonoe", "Sponde", "Pasithee",
		"Megaclite", "Sinope", "Callirrhoe", "Aoede", "Kalyke", "Kore", "Cyllene", "Eukelade", "Pasiphae", "Hegemone",
		"Arche", "Iocaste", "Erinome", "Harmony", "Eupheme", "Thelxinoe", "Eirene", "Philophrosyne", }, 4, true, new AsteroidCluster("Jupiter's Belt", "Jupiter", 175'000, {"C-type", "D-type"}), "Class I gas giant") {}
};