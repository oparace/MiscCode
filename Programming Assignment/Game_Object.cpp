

#include <iostream>
#include "Game_Object.h"
using namespace std;


Game_Object::Game_Object(char in_code)
{
	display_code = in_code;
	id_num = 1;
	state = 's';
	std::cout << "Game_Object constructed"<<endl;
}


Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
	display_code = in_code;
	id_num = in_id;
	state = 's';
	location = in_loc;

	std::cout << "Game_Object constructed"<<endl;
}


Game_Object::~Game_Object()
{
	std::cout << "Game_Object destructed."<<endl;
}

Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

char Game_Object::get_state()
{
	return state;
}

void Game_Object::show_status()
{
	std::cout << display_code << id_num << " at " << location;
}

void Game_Object::drawself(char* ptr)
{
	*ptr = display_code;

	int i = id_num;
	*(ptr + 1) = i + '0';
}
