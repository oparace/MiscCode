#include <iostream>
#include "Alien.h"
#include <math.h>

using namespace std;

Alien::Alien() : Game_Object('X')
{
  attack_strength = 2;
  range = 2.0;
  health = 5.0;
  target = NULL;
  speed = 5;
  cout << "Default Alien constructed" << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc) : Game_Object(in_loc, in_id, 'X')
{
  attack_strength = 2;
  range = 2.0;
  health = 5.0;
  target = NULL;
  speed = 5;
  cout << "Alien constructed" << endl;
}



bool Alien::update()
{
  bool arrive;
  if (state == 'x')
  {
    return false;
  }
  switch(state)
  {
    case 's':
    {
      return false;
    }
    case 'm':
    {
      arrive = Alien::update_location();
      if (arrive)
      {
        state = 's';
        return true;
      }
      else
      {
        return false;
      }
    }
    case 'a':
    {
      Cart_Point AlienLoc = get_location();
      Cart_Point AstroLoc = target -> get_location();
      double dist = cart_distance(AlienLoc, AstroLoc);
      if (dist > range)
      {
        if(!compMode)
        {
          cout << display_code << id_num << ": Target is out of range" << endl;
        }
        cout << display_code << id_num << ": Charge." << endl;
        state = 's';
        return true;
      }
      else
      {
        if (target -> is_alive())
        {
          cout << display_code << id_num << ": Destroy!" << endl;
          target -> take_hit(attack_strength);
          return false;
        }
        else
        {
          cout << display_code << id_num << ": I triumph." << endl;
          state = 's';
          return true;
        }
      }
    }
    default:
    {
      cout << "Error!" << endl;
      return false;
    }
  }
}

void Alien::start_attack(Person* in_target)
{
    Cart_Point AlienLoc = get_location();
    Cart_Point AstroLoc = in_target -> get_location();
    double dist = cart_distance(AlienLoc, AstroLoc);
    
    if (dist <= range)
    {
        if (state == 'a')
        {
            cout << display_code << id_num << ": Destroy!" << endl;
            in_target -> take_hit(attack_strength);
        }
        else
        {
            cout << display_code << id_num << ": Smash!" << endl;
            target = in_target;
            state = 'a';
        }
    }
    
    if (!compMode && dist > range)
    {
        cout << display_code << id_num << ": Target is out of range" << endl;
    }
}

void Alien::show_status()
{
  cout << "Alien status: ";
  Game_Object::show_status();
  switch (state)
  {
    case 'm':
      cout << " moving at speed " << speed << " to " << destination << " at each step of " << delta << endl;
      break;
    case 's':
      cout << " is stopped." << endl;
      break;
    case 'a':
      cout << " attacking astronaut A" << target -> get_id() << endl;
      break;
    case 'x':
      cout << " is dead." << endl;
  }
}

void Alien::start_moving(Cart_Point dest)
{
  if (state == 'x' && !compMode)
  {
    cout << "I can't move, I am dead." << endl;
  }
  else
  {
    if (dest.x == location.x && dest.y == location.y && !compMode)
    {
      cout << "I am already at location" << endl;
    }
    else
    {
      setup_destination(dest);
      state = 'm';
      if (!compMode)
      {
        cout << "Moving " << id_num << " to " << dest << endl;
        cout << display_code << id_num << ": On my way." << endl;
      }
    }
  }
}

void Alien::stop()
{
  if (state == 'x' && !compMode)
  {
    cout << "I can't move, I am dead." << endl;
  }
  else if (!compMode)
  {
    state = 's';
    cout << display_code << id_num << ": Stopped." << endl;
  }
}

bool Alien::update_location()
{
  setup_destination(destination);
  if(delta.x == 0 && delta.y == 0)
  {
    return true;
  }
  Cart_Vector newdist = destination - location;
  newdist.x = fabs(newdist.x);
  newdist.y = fabs(newdist.y);

  if (newdist.x <= fabs(delta.x) && newdist.y <= fabs(delta.y))
  {
    location = destination;
    cout << display_code << id_num << ": I'm there!" << endl;
    return true;
  }
  else
  {
    location = location + delta;
    cout << display_code << id_num << ": step..." << endl;
    return false;
  }
}

void Alien::setup_destination(Cart_Point dest)
{
  destination = dest;
  Cart_Vector cv = destination - location;
  delta = cv / ((cart_distance(destination, location) / speed));
}

bool Alien::is_alive()
{
  if (state == 'x')
    return false;
  else
    return true;
}



double Alien::get_speed()
{
  return speed;
}

double Alien::get_range()
{
  return range;
}

void Alien::change_speed(double in_speed) 
{
  speed = in_speed;
}


void Alien::take_hit(int Pattack_strength)
{
    health -= Pattack_strength;
    if (health <= 0)
    {
        cout << display_code << id_num << ": I'm dying" << endl;
        state = 'x';
    }
    else if (health < 3)
    {
        display_code = tolower(display_code);
        cout << display_code << id_num << ": Ouch!" << endl;
    }
    else
    {
        cout << display_code << id_num << ": Ouch!" << endl;
    }
}

