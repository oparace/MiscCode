#include <iostream>
#include "Astronaut.h"
using namespace std;


bool first_arrived = false;


Astronaut::Astronaut(): Person('A')
{
	display_code = 'A';
	amount_moonstones = 0;
	amount_oxygen = 20;
	home = NULL;
	depot = NULL;
	std::cout << "Astronaut default constructed."<<endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc): Person(in_loc, in_id, 'A')
{
	display_code = 'A';
	location = in_loc;
	id_num = in_id;
	amount_moonstones = 0;
	amount_oxygen = 20;
	home = NULL;
	depot = NULL;
	std::cout << "Astronaut constructed."<<endl;
}


Astronaut::~Astronaut()
{
    std::cout << "Astronaut destructed."<<endl;
}



void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
	if (state != 'l' && amount_oxygen != 0)
	{
		depot = inputDepot;
		Person::setup_destination(depot->get_location());
		if (location.x == inputDepot->get_location().x && location.y == inputDepot->get_location().y)
		{
			state = 'g';
		}
		else
		{
			state = 'o';
		}
		std::cout <<"Astronaut " << display_code << get_id() << " supplying at Oxygen_Depot " <<inputDepot->get_id() << '\n';
		std::cout << display_code<< get_id() << ": Yes, my lord."<<endl;
	}

	else if (state == 'l')
	{
        std::cout<< display_code << get_id() <<": I can't move. I'm locked in."<<endl;
	}

}

void Astronaut::go_to_station(Space_Station* inputStation)
{
	if (amount_oxygen != 0)
	{
		home = inputStation;
		std::cout << "Astronaut " << display_code << get_id() << " locking in at Space_Station " << home->get_id() << ". "<<endl;
		Person::setup_destination(home->get_location());
		state = 'l';
	}
	else 
	{
		std::cout<< display_code << get_id() <<": HELP. I can't move. I'm out of oxygen."<<endl;
	}
}


void Astronaut::start_depositing(Space_Station* inputStation) 
{
	home = inputStation;
	Person::setup_destination(home->get_location());
	if (amount_oxygen != 0)
	{
		if (location.x == inputStation->get_location().x && location.y == inputStation->get_location().y)
		{
			state = 'd';
		}
		else
		{
			state = 'i';
		}
		std::cout <<"Astronaut " << display_code << get_id() << " depositing to Space_Station " <<inputStation->get_id() << '\n';
		std::cout << display_code<< get_id() << ": Yes, my lord."<< endl;
	}

	else
	{
		std::cout<< display_code << get_id() <<": I can't move. I'm out of oxygen."<<endl;
	}
}

bool Astronaut::update()
{
	if (amount_oxygen != 0)
	{
		switch (Person::state)
		{
			case 's': 
				return false;
			break;

			case 'm':
			{
				if (Person::update_location())
				{
					state = 's';
					return true;
				}	
				else
				{
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}
			}
			break;

			case 'o':
			{
				if (Person::update_location())
				{
					state = 'g';
					return true;
				}
				else
				{
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}
			}	
			break;

			case 'g':
			{
				
				double amountExtracted = depot->extract_oxygen();
				std::cout << display_code << get_id() << ": Got " << amountExtracted << " more oxygen."<<endl;
				amount_oxygen = amount_oxygen + amountExtracted;
				state = 's';
				return true;
			}
			break;

			case 'i':
			{
				if (Person::update_location())
				{
					state = 'd';
					return true;
				}
				else
				{
					amount_moonstones++;
					amount_oxygen--;
					return false;
				}
			}		

			break;

			case 'd':
			{
				std::cout << display_code << get_id() << ": Deposit " << amount_moonstones << " moonstones." <<endl;
				home->deposit_moonstones(amount_moonstones);
				amount_moonstones = 0;
				state = 's';
				return true;
			}
			break;

			case 'l':
			{	

				if (get_location().x != home->get_location().x || get_location().y != home-> get_location().y)
				{
					first_arrived = Person::update_location();

					if (!first_arrived)
					{
						amount_moonstones++;
						amount_oxygen--;;
						return false;
					}

					else
					{
						if (home->add_astronaut())
						{
							bool first_arrived = true;
							return true;
						}

						else
						{
							state = 's';
							return false;
						}
					}
				}

				 
				else if (get_location().x == home->get_location().x && get_location().y == home->get_location().y)
				{	
					if (!first_arrived)
					{
						home->add_astronaut();
						return true;
					}

					else
					{
						return false;
					}
					return false;
				}	

				break;
			}

		}
	}

	else if (amount_oxygen == 0)
	{
		std::cout << display_code << get_id() << ": I can't move. I'm out of oxygen."<<endl;
		state = 'l';
		return true;
	}
}


void Astronaut::show_status()
{
	if (state != 'l')
	{
		std::cout << "Astronaut status: ";
		Person::show_status();
		switch (Person::state)
		{
			case 's': 
				std::cout << " with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones. "<<endl;
			break;

			case 'm':
				std::cout << '\n';
			break;

			case 'o':
				std::cout <<" is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moonstones."<<endl;
			break;

			case 'g':
				std::cout << " is getting oxygen from Depot."<<endl;
			break;

			case 'i':
				std::cout <<" is inbound to home with load: " << amount_moonstones << " moon stones and " << amount_oxygen << " oxygen."<<endl;
			break;

			case 'd':
				std::cout << " is depositing " << amount_moonstones << " moonstones."<<endl;
			break;

			case 'l':
		
			std::cout << " is locked at Space Station."<<endl;
			break;
		}
	}

	else if (state == 'l')
	{
		if (amount_oxygen != 0)
		{
			std::cout << "Astronaut status: ";
			Game_Object::show_status();
			std::cout << " is locked at Space Station."<<endl;
		}
		else
		{
			std::cout << "Astronaut status: ";
			Game_Object::show_status();
			std::cout <<  " is locked. Out of oxygen."<<endl;
		}
	}	


}

