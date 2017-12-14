
#include <iostream>
#include "Game_Command.h"
using namespace std;


void do_move_command(Model& gameModel, int id, double x, double y)
{
	Cart_Point target(x,y);
	gameModel.get_Person_ptr(id)->start_moving(target);
	
}

void do_work_command(Model& gameModel, int personID, int depotID)
{
	Person* ptr1;
	Oxygen_Depot* ptr2;

	ptr1 = gameModel.get_Person_ptr(personID);
	ptr2 = gameModel.get_Oxygen_Depot_ptr(depotID);

	ptr1->start_supplying(ptr2);
}


void do_deposit_command(Model& gameModel, int personID, int stationID)
{
	Person* ptr1;
	Space_Station* ptr2;
	ptr1 = gameModel.get_Person_ptr(personID);
	ptr2 = gameModel.get_Space_Station_ptr(stationID);
	ptr1->start_depositing(ptr2);
}

void do_stop_command(Model& gameModel, int personID)
{
	gameModel.get_Person_ptr(personID)->stop();
}


void do_lock_command(Model& gameModel, int personID, int stationID)
{
	Person* ptr1;
	Space_Station* ptr2;
	ptr1 = gameModel.get_Person_ptr(personID);
	ptr2 = gameModel.get_Space_Station_ptr(stationID);
	if (ptr2->get_state() == 'u')
	{
		ptr1->go_to_station(ptr2);
	}

	else
	{
		std::cout <<"Astronaut " << ptr1->get_id() << " cannot lock in at Space_Station " << ptr2->get_id() << " because it is not upgraded."<<endl;
	}
}
void do_go_command(Model& gameModel)
{
	gameModel.update();
}

void do_run_command(Model& gameModel)
{
	bool roll;
	for (int i = 0; i < 5; i++)
	{
		roll = gameModel.update();
		if(roll == true)
		{
			break;
		}
	}
}

  void do_quit_command(Model& gameModel)
{
	std::cout << "Terminating program.\n";
}

void do_output_command(Model& gameModel)
{
	gameModel.show_status();
}


