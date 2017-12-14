#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Game_Object.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"

class Person: public Game_Object
{
	public:
		Person();
		Person(char);
		Person(Cart_Point, int, char);
		virtual ~Person();

		void start_moving(Cart_Point);
		void stop();
		void show_status();
		virtual void go_to_station(Space_Station* inputStation); 
		virtual void start_depositing(Space_Station* inputStation);
		virtual void start_supplying(Oxygen_Depot* inputDepot);  

		virtual bool update() = 0;
		
	protected:
		bool update_location();
		void setup_destination(Cart_Point);
	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;

};


#endif
