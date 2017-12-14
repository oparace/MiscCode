
#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"
#include "Game_Command.h"
#include "View.h"
#include <sstream>
using namespace std;


int main() 
{
   
	std::cout << "EC327: Introduction to Software Engineering"<<endl;
	std::cout <<"Fall 2017"<<endl;
	std::cout << "Programming Assignment 3"<<endl;
	Model model;
	View view;
	bool run = true;
	int errorcheck;
	model.show_status();

	while (run)
	{
		model.display(view);
		errorcheck = retrieveCommand(model);
		if (errorcheck == 1)
		{
			run = false;
		}
		else if (errorcheck == 2)
		{
			std::cout << "ERROR: Please enter a valid command!"<<endl;
		}

	}

	return 0;
}

int retrieveCommand(Model& model)
{
	std::cout <<"Enter command: ";
	std::string userIn;
	getline(std::cin, userIn);
	std::istringstream ss(userIn);
	char alpha;
	int val1;
	int val2;
	int val3;

		ss >> alpha;
	if (!ss.eof())
	{
		ss >> val1;
		if (!ss.eof())
		{
			ss >> val2;
			if (!ss.eof())
			{
				ss >> val3;
			}
		}
	}

	switch (alpha)
	{
		case 'm': 
			do_move_command(model, (int)val1, (int)val2, (int)val3);
			return 0;
		break;

		case 'w':
			do_work_command(model, (int)val1, (int)val2);
			return 0;
		break;

		case 'd':
			do_deposit_command(model, (int)val1, (int)val2);
			return 0;

		case 's':
			do_stop_command(model, (int)val1);
			return 0;
		break;

		case 'g':
			std::cout << "Advancing one tick."<<endl;
			do_go_command(model);
			do_output_command(model);
			return 0;
		break;

		case 'r':
			std::cout << "Advancing to next event."<<endl;
			do_run_command(model);
			do_output_command(model);
			return 0;
		break;

		case 'q':
			do_quit_command(model);
			return 1;
		break;

		case 'l':
			do_lock_command(model, (int)val1, (int)val2);
			return 0;
		break;

		case 'o':
			do_output_command(model);
			return 0;
		break;
	}
	
	return 2;
}
