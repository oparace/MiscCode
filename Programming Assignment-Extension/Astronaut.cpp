#include <iostream>
#include "Astronaut.h"

using namespace std;

Astronaut::Astronaut() : Person('A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  there = false;
  depot = NULL;
  home = NULL;
  cout << "Astronaut default constructed." << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc) : Person(in_loc, in_id, 'A')
{
  amount_moonstones = 0;
  amount_oxygen = 20;
  there = false; 
  depot = NULL;
  home = NULL;
  cout << "Astronaut constructed." << endl;
}

Astronaut::~Astronaut()
{
  cout << "Astronaut destructed." << endl;
}

bool Astronaut::update()
{
  bool arrive;
  double extract;
  if (state == 'x')
  {
    return false;
  }
  else
  {
    if (health < 3)
    {
      display_code = tolower(display_code);
    }
    switch (state)
    {
      case 's':
      {
        return false;
        break;
      }
      case 'm':
      {
        arrive = Person::update_location();
        if (arrive)
        {
          state = 's';
          return true;
        }
        else
        {
          amount_oxygen--;
          if (amount_oxygen <= 0)
          {
            state = 'x';
            cout << "I'm out of oxygen. I am dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++;
          }
          return false;
        }
        break;
      }
      case 'o':
      {
        arrive = Person::update_location();
        if (arrive)
        {
          state = 'g';
          return true;
        }
        else
        {
          amount_oxygen--;

          if (amount_oxygen <= 0)
          {
            state = 'x';
            cout << "I'm out of oxygen. I'm dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++;
          }
          return false;
        }
        break;
      }
      case 'g':
      {
        extract = depot -> extract_oxygen();
        amount_oxygen += extract;
        cout << display_code << id_num << ": Got " << extract << " more oxygen." << endl;
        state = 's';
        return true;
        break;
      }
      case 'i':
      {
        arrive = Person::update_location();
        if (arrive)
        {
          state = 'd';
          return true;
        }
        else
        {
          amount_oxygen--;
          if (amount_oxygen <= 0)
          {
            state = 'x';
            cout << "I'm out of oxygen. I'm dying!" << endl;
            return true;
          }
          else
          {
            amount_moonstones++;
          }
          return false;
        }
        break;
      }
      case 'd':
      {
        cout << display_code << id_num << ": Deposit " << amount_moonstones << " moon stones." << endl;
        home -> deposit_moonstones(amount_moonstones);
        amount_moonstones = 0;
        state = 's';
        return true;
        break;
      }
      case 'a':
      {
        Cart_Point AstroLoc = get_location();
        Cart_Point AlienLoc = target -> get_location();
        double dist = cart_distance(AlienLoc, AstroLoc);
        if (dist > range)
        {
          cout << display_code << id_num << ": Target is out of range" << endl;
          cout << display_code << id_num << ": Chaaaaarge." << endl;
          state = 's';
          return true;
        }
        else
        {
          if (target -> is_alive())
          {
            cout << display_code << id_num << ": Take that!" << endl;
            target -> take_hit(attack_strength);
            return false;
          }
          else
          {
            cout << display_code << id_num << ": I win." << endl;
            state = 's';
            return true;
          }
        }
      }
      case 'l':
      {
        if (amount_oxygen <= 0)
        {
          return false;
        }
        else
        {
          Cart_Point dest = home -> get_location();
          arrive = Person::update_location();

         

          if (arrive && !there)
          {
            home -> add_astronaut();
            there = true;
            return true;
          }
          else
          {
            return false;
          }
        }
        break;
      }
      default:
      {
        return false;
      }
    }
  }
}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
  if (state == 'x')
  {
    cout << "I can't move, I am dead." << endl;
  }
  else
  {
    depot = inputDepot;
    Person::setup_destination(inputDepot -> get_location());
    state = 'o';
    cout << "Astronaut " << get_id() << " supplying from Oxygen Depot " << inputDepot -> get_id() << endl;
    cout << display_code << get_id() << ": Yes, my lord." << endl;
  }
}

void Astronaut::start_depositing(Space_Station* inputStation)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    home = inputStation;
    Person::setup_destination(inputStation -> get_location());
    state = 'i';
    cout << "Astronaut " << get_id() << " depositing to Space Station " << inputStation -> get_id() << endl;
    cout << display_code << get_id() << ": Yes, my lord." << endl;
  }
}

void Astronaut::go_to_station(Space_Station* inputStation)
{
  if (state == 'x')
  {
    cout << "I can't move, I'm dead." << endl;
  }
  else
  {
    home = inputStation;
    state = 'l';
    Person::setup_destination(inputStation -> get_location());
    cout << "Astronaut " << get_id() << " locking in at Space Station " << inputStation -> get_id() << endl;
  }
}

void Astronaut::show_status()
{
  cout << "Astronaut status: ";
  Person::show_status();
  switch (state)
  {
    case 's':
    {
      cout << " stopped with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
      break;
    }
    case 'm':
    {
      cout << endl;
      break;
    }
    case 'o':
    {
      cout << " is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moon stones." << endl;
      break;
    }
    case 'g':
    {
      cout << " is getting oxygen from the depot" << endl;
      break;
    }
    case 'i':
    {
      cout << " is inbound to home with load: " << amount_moonstones << " moon stones and " << amount_oxygen << " oxygen" << endl;
      break;
    }
    case 'd':
    {
      cout << " depositing " << amount_moonstones << " moon stones" << endl;
      break;
    }
    case 'l':
    {
      cout << " is locked at Space Station." << endl;
      break;
    }
    case 'a':
    {
      cout << " attacking alien X" << target -> get_id();
    }
    case 'x':
    {
      cout << endl;
      break;
    }
  }
}
