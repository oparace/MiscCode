

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstdlib>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "View.h"

class Model
{
public:
	Model();
	~Model();

	Person * get_Person_ptr(int id);
	Oxygen_Depot * get_Oxygen_Depot_ptr(int id);
	Space_Station * get_Space_Station_ptr(int id);
	bool update();
	void show_status();
	void display(View &view);
private: 
	Model(const Model &obj); 

	int time;
	int count_down;

	Game_Object * object_ptrs[10];
	int num_objects;
	Person * person_ptrs[10];
	int num_persons;
	Oxygen_Depot * depot_ptrs[10];
	int num_depots;
	Space_Station * station_ptrs[10];
	int num_station;
};
#endif
