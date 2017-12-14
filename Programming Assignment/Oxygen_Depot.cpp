

#include <iostream>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
using namespace std;

Oxygen_Depot::Oxygen_Depot(): Game_Object('O')
{
	display_code = 'O';
	state = 'f';
	amount_oxygen = 50;
	std::cout << "Oxygen_Depot constructed"<<endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId): Game_Object(inputLoc, inputId, 'O')
{
	id_num = inputId;
	location = inputLoc;

	display_code = 'O';
	state = 'f';
	amount_oxygen = 50;
	std::cout << "Oxygen_Depot constructed"<<endl;
}

Oxygen_Depot::~Oxygen_Depot()
{
	std::cout << "Oxygen_Depot destructed."<<endl;
}

bool Oxygen_Depot::is_empty()
{
	if (amount_oxygen == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}


double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	if (amount_oxygen >= amount_to_extract)
	{
		amount_oxygen -= amount_to_extract;
		return amount_to_extract;
	}
	else 
	{
		double tempAmount = amount_oxygen;
		amount_oxygen = 0;
		return tempAmount;
	}
}

bool Oxygen_Depot::update()
{
	if(amount_oxygen == 0 && state == 'f')
	{
		display_code = 'o';
		state = 'e';
		std::cout << "Oxygen_Depot " <<id_num << " has been depleted."<<endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Oxygen_Depot::show_status()
{
	std::cout << "Oxygen Depot status: " << display_code << id_num << " at location " << location << " contains " << amount_oxygen << endl;
}


