#ifndef ASTRONAUT_H
#define ASTRONAUT_H
#include <iostream>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"

class Astronaut: public Person
{
	public:
		Astronaut();
		Astronaut(int, Cart_Point);
		~Astronaut();
		void show_status(); 
		void go_to_station(Space_Station* inputStation); 
		void start_depositing(Space_Station* inputStation);
		void start_supplying(Oxygen_Depot* inputDepot);  
		bool update();

	private: 
		double amount_moonstones;
		double amount_oxygen;
		Oxygen_Depot* depot;
		Space_Station* home;
};

#endif
