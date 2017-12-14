#include <iostream>
#include "Person.h"
#include <cmath>
using namespace std;
	

Person::Person(): Game_Object('P')
{
	speed = 5;
	std::cout <<"Person constructed. "<<endl;
}

Person::Person(char in_code): Game_Object(in_code)
{
	speed = 5;
	std::cout <<"Person constructed. "<<endl;
	state = 's';
	display_code = in_code;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code): Game_Object(in_loc, in_id, in_code)
{
	speed = 5;
	std::cout <<"Person constructed. "<<endl;
	state = 's';
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
}


Person::~Person()
{
	std::cout << "Person destructed."<<endl;
}


bool Person::update_location()
{
	Cart_Point updatedLocation = location + delta;
	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
	{
		std::cout << display_code << get_id() << ": I'm there!"<<endl;
		location = destination;
		return true;
	}
	else
	{
		std::cout << display_code << get_id() << ": step..."<<endl;
		location = updatedLocation;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest)
{
	destination = dest;
	delta = (destination - location) * (speed / cart_distance(destination, location));

}
void Person::start_moving(Cart_Point dest)
{
	if (state != 'l')
	{
		destination = dest;
		setup_destination(destination);

		if (location.x == destination.x && location.y == destination.y)
		{
			std::cout << display_code << get_id()<< ": I'm already there. see?"<<endl;
		}
		else 
		{
			state = 'm';
			std::cout << "Moving " << get_id() << " to " << dest << endl;
			std::cout << display_code << id_num << ": On my way."<<endl;
		}
	}

	else
	{
		std::cout << "Moving " << get_id() << " to " << dest << endl;
		std::cout << "I can't move. I'm locked in."<<endl;
	}
}

void Person::stop()
{
	if (state != 's')
	{
		state = 's';
		std::cout << "Stopping " << get_id() << endl;
		std::cout << display_code << get_id() << ": " << "All right."<<endl;
	}
	else
	{
		std::cout << display_code << get_id() << ": I'm already stopped."<<endl;
	}

}

void Person::show_status()
{
	Game_Object::show_status();

	if (state == 's') 
	{
		std::cout << " is stopped"; 
    }
    else 
    {
        std::cout << " moving at speed of " << speed << " towards " << destination << " at each step of " << delta;
    }
    
}


void Person::go_to_station(Space_Station* inputStation)
{
	std::cout << "Sorry, I can't lock into a station."<<endl;
}

void Person::start_depositing(Space_Station* inputStation)
{
	std::cout << "Sorry, I can't work a station."<<endl;
}

void Person::start_supplying(Oxygen_Depot* inputDepot)
{
	std::cout << "Sorry, I can't work a depot."<<endl;
}
