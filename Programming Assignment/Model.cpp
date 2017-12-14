
#include <iostream>
#include "Model.h"
using namespace std;


bool stations_ready = false;
bool launch_started = false;
bool stations_manned = false;

int ready_count = 0;
int manned_count = 0;

Model::Model()
{
	
	time = 0;
	count_down = 10;

	Cart_Point spawn1(5,1);
	Cart_Point spawn2(10,1);
	Cart_Point spawn3(1,20);
	Cart_Point spawn4(10,20);
	Cart_Point spawn5(5,5);


	
	object_ptrs[0] = new Astronaut(1, spawn1);
	person_ptrs[0] = dynamic_cast<Astronaut*>(object_ptrs[0]);

	object_ptrs[1] = new Astronaut(2, spawn2);
	person_ptrs[1] = dynamic_cast<Astronaut*>(object_ptrs[1]);

	object_ptrs[2] = new Oxygen_Depot(spawn3, 1);
	depot_ptrs[0] = dynamic_cast<Oxygen_Depot*>(object_ptrs[2]);

	object_ptrs[3] = new Oxygen_Depot(spawn4, 2);
	depot_ptrs[1] = dynamic_cast<Oxygen_Depot*>(object_ptrs[3]);

	object_ptrs[4] = new Space_Station();
	station_ptrs[0] = dynamic_cast<Space_Station*>(object_ptrs[4]);

	object_ptrs[5] = new Space_Station(spawn5, 2);
	station_ptrs[1] = dynamic_cast<Space_Station*>(object_ptrs[5]);

	num_objects = 5;
	num_persons = 2;
	num_depots = 2;
	num_station = 2;

	std::cout << "Model default constructed."<<endl;
}



Model::~Model()
{
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}
	std::cout <<"Model destructed."<<endl;
}


Person* Model::get_Person_ptr(int id)
{
	Person* outPtr;
	outPtr = person_ptrs[id - 1];
	return outPtr;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
	Oxygen_Depot* outPtr;
	outPtr = depot_ptrs[id - 1];
	return outPtr;
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
	Space_Station* outPtr;
	outPtr = station_ptrs[id - 1];
	return outPtr;
}

bool Model::update() 
{
	time++;
	ready_count = 0;
	manned_count = 0;


	if (!stations_ready)
	{
		for (int i = 0; i < num_station; i++)
		{
			char tempCheck = station_ptrs[i]->get_state();
			if (tempCheck == 'u')
			{
				ready_count++;
			}
		}

		if (ready_count == num_station)
		{
			stations_ready = true;
		}
	}

	
	if (!stations_manned)
	{
		int Check;
		for (int i = 0; i < num_station; i++)
		{
			Check = station_ptrs[i]->get_astronauts();
			if (Check >= 1)
			{
				manned_count++;	
			}
		}
		if (manned_count == num_station)
		{
			stations_manned = true;
		}
	}



	if (stations_ready && stations_manned)
	{
			std::cout << "Ready for takeoff? " << count_down << "..."<<endl;
			std::cout << "Blast Off! You Win!"<<endl;
			exit(0);
	}


	else
	{
		bool roll = false;
		
		if (stations_ready)
		{
			if (count_down == 0)
			{
				std::cout << "Unmanned take off... You lose!"<<endl;
				exit(0);
			}
			else
			{
				std::cout << "Ready for takeoff? " << count_down << "..."<<endl;
			}

			count_down--;
			std::cout << "Missing " << (num_station - manned_count) << " astronauts!"<<endl;
		}

		
		for (int i = 0; i < num_objects + 1; i++)
		{
			if (object_ptrs[i]-> update())
			{
				roll = true;
			}
		}
		return roll;
	}

}

void Model::display(View &view)
{
	
	view.clear();

	for (int i = 0; i < num_objects + 1; i++)
	{
		view.plot(object_ptrs[i]);
	}

	view.draw();

}
void Model::show_status()
{
	std::cout << "Time: " << time << '\n';
	for (int i = 0; i < num_objects + 1; i++)
		{
			object_ptrs[i]-> show_status();
		}
}



