
#include <iostream>
#include "Space_Station.h"
using namespace std;

Space_Station::Space_Station(): Game_Object('s')
{
	amount_moonstones = 0;
	number_astronauts = 0;
	state = 'o';
	std::cout << "Space_Station constructed"<<endl;

}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId): Game_Object(inputLoc, inputId,'s')
{
	amount_moonstones = 0;
	number_astronauts = 0;
	state = 'o';
	id_num = inputId;
	location = inputLoc;
	std::cout << "Space_Station constructed"<<endl;
}


Space_Station::~Space_Station()
{
	std::cout<<"Space_Station destructed"<<endl;
}

void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones = deposit_amount + amount_moonstones;
}

bool Space_Station::add_astronaut()
{
	if (state == 'u')
	{
		number_astronauts++;
		return true;
	}
	else
	{
		std::cout << "Station not upgraded. Astronaut cannot enter."<<endl;
		return false;
	}
}

int Space_Station::get_astronauts()
{
	return number_astronauts;
}

bool Space_Station::update() 
{
	if (amount_moonstones >= 10 && state == 'o')
	{
		display_code = 'S';
		state = 'u';
		std::cout << display_code << id_num << " has been upgraded."<<endl;
		return true;
	}

	else
	{
		return false;
	}
}
void Space_Station::show_status()
{
	std::cout <<"Space Station status: " << display_code << id_num << " at location " << location << " contains " << amount_moonstones << " moon stones"<< " and contains " <<number_astronauts << " astronauts. ";
	if (display_code == 'S')
	{
		std::cout << "Upgraded."<<endl;
	}
	else
	{
		std::cout << "Not yet upgraded."<<endl;
	}

}
