
#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"
#include "Model.h"


void do_move_command(Model&, int, double, double);


void do_work_command(Model&, int, int);


void do_deposit_command(Model&, int, int);

void do_go_command(Model&);


void do_run_command(Model&);


void do_quit_command(Model&);


void do_output_command(Model&);

int retrieveCommand(Model&);

void do_stop_command(Model&, int);


void do_lock_command(Model&, int, int);



#endif


