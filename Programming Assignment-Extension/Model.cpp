#include <iostream>
#include "Model.h"

using namespace std;

Model::Model()
{
  timer = 0;
  count_down = 10;

  alive = 2;

  Cart_Point pt1 = Cart_Point(5,1);
  Cart_Point pt2 = Cart_Point(10,1);
  Cart_Point pt3 = Cart_Point(1,20);
  Cart_Point pt4 = Cart_Point(10,20);
  Cart_Point pt5 = Cart_Point(5,5);
  Cart_Point pt6 = Cart_Point(7,14);
  Cart_Point pt7 = Cart_Point(7, 5);

  Astronaut* ptrA1 = new Astronaut(1,pt1);
  Astronaut* ptrA2 = new Astronaut(2, pt2);

  Alien* ptrX1 = new Alien(1, pt6);
  Alien* ptrX2 = new Alien(2, pt7);

  Oxygen_Depot* ptrD1 = new Oxygen_Depot(pt3, 1);
  Oxygen_Depot* ptrD2 = new Oxygen_Depot(pt4, 2);

  Space_Station* ptrS1 = new Space_Station();
  Space_Station* ptrS2 = new Space_Station(pt5, 2);

  object_ptrs.push_back(ptrA1);
  object_ptrs.push_back(ptrA2);
  object_ptrs.push_back(ptrD1);
  object_ptrs.push_back(ptrD2);
  object_ptrs.push_back(ptrS1);
  object_ptrs.push_back(ptrS2);
  object_ptrs.push_back(ptrX1);
  object_ptrs.push_back(ptrX2);

  active_ptrs.push_back(ptrA1);
  active_ptrs.push_back(ptrA2);
  active_ptrs.push_back(ptrD1);
  active_ptrs.push_back(ptrD2);
  active_ptrs.push_back(ptrS1);
  active_ptrs.push_back(ptrS2);
  active_ptrs.push_back(ptrX1);
  active_ptrs.push_back(ptrX2);

  person_ptrs.push_back(ptrA1);
  person_ptrs.push_back(ptrA2);

  depot_ptrs.push_back(ptrD1);
  depot_ptrs.push_back(ptrD2);

  station_ptrs.push_back(ptrS1);
  station_ptrs.push_back(ptrS2);

  alien_ptrs.push_back(ptrX1);
  alien_ptrs.push_back(ptrX2);

  cout << "Model default constructed" << endl;
}

Model::~Model()
{
  for (list <Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
  {
    delete *it;
  }
  cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id)
{
  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Alien* Model::get_Alien_ptr(int id)
{
  for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
  for (list <Oxygen_Depot*>::iterator it = depot_ptrs.begin(); it != depot_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end(); ++it)
  {
    if((*it) -> get_id() == id)
    {
      return *it;
    }
  }
  return 0;
}

bool Model::update()
{
  timer++;
  srand(timer);
  int gravity = rand() % 10;

  
  if (gravity == 0)
  {
    if(person_ptrs.front() -> get_speed() != 2.5)
    {
      cout << "Gravity is now greater!" << endl;
    
      for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
      {
        (*it) -> change_speed(2.5);
      }
      for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
      {
        (*it) -> change_speed(2.5);
      }
    }
  }
  else if (gravity == 1)
  {
    if(person_ptrs.front() -> get_speed() != 5)
    {
      cout << "Gravity is back to normal!" << endl;
      for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
      {
        (*it) -> change_speed(5);
      }
      for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
      {
        (*it) -> change_speed(5);
      }
    }
  }
  else if (gravity == 2)
  {
    if(person_ptrs.front() -> get_speed() != 10)
    {
      cout << "Gravity is now less!" << endl;
      for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
      {
        (*it) -> change_speed(10);
      }
      for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
      {
        (*it) -> change_speed(10);
      }
    }
  }

  alive = 0;

  for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
    if ((*it) -> get_state() == 'x')
    {
      it = active_ptrs.erase(it);
    }
  }

  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    if ((*it) -> is_alive())
    {
      alive++;
    }
  }

  
  if (this -> compMode)
  {
    bool attack = false;
    for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
    {
      
      (*it) -> compMode = true;
      if ((*it) -> get_state() != 'x')
      {
        if (((*it) -> get_state() != 'a') && ((*it) -> get_state() != 'm'))
        {
          for (list <Person*>::iterator it2 = person_ptrs.begin(); it2 != person_ptrs.end(); ++it2)
          {
            Cart_Point AlienLoc = (*it) -> get_location();
            Cart_Point AstroLoc = (*it2) -> get_location();
            double dist = cart_distance(AlienLoc, AstroLoc);

            if ((*it2) -> is_alive() && dist < (*it) -> get_range())
            {
              (*it) -> start_attack(*it2);
              attack = true;
              break;
            }
          }
          if(!attack)
          {
            for (list <Person*>::iterator it2 = person_ptrs.begin(); it2 != person_ptrs.end(); ++it2)
            {
              if ((*it2) -> is_alive())
              {
                Cart_Point dest = (*it2) -> get_destination();
                (*it) -> start_moving(dest);
                break;
              }
            }
          }
        }
      }
    }
  }


  bool upgraded = true;

  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end() && upgraded; ++it)
  {
    if ((*it) -> get_state() != 'u')
    {
      upgraded = false;     }
  }

  bool atStation = true;
  bool tempStation = false;
  for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
  {
    if ((*it) -> is_alive())
    {
      for (list <Space_Station*>::iterator it2 = station_ptrs.begin(); it2 != station_ptrs.end(); ++it2)
      {
        
        Cart_Point personloc = (*it) -> get_location();
        Cart_Point stationloc = (*it2) -> get_location();

        if((personloc.x == stationloc.x) && (personloc.y == stationloc.y) && ((*it) -> get_state() == 'l'))
        {
          tempStation = true;
        }
      }
    }
    if (!tempStation)
    {
      atStation = false;
    }
    else
    {
      atStation = true;
    }
    
  }

  bool allAstro = true;
  int missing = 0;
  for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end(); ++it)
  {
    missing += (*it) -> get_astronauts();
    if ((*it) -> get_astronauts() < 1)
    {
      allAstro = false;
    }
  }
  missing = alive - missing;
  bool check = false;

  if(!upgraded)
  {
    bool temp;
    for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
      temp = (*it) -> update();
      if (temp)
      {
        check = true;
      }
    }
  }
  else if (!allAstro || !atStation || missing)
  {
    cout << "Ready for takeoff? " << count_down << "..." << endl;
    cout << "Missing " << missing << " astronauts!" << endl;
    count_down--;

    if (count_down <= 0)
    {
      cout << "Unmanned takeoff...you lose!" << endl;
      exit(0);
    }

 
    bool temp;
    for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
    {
      temp = (*it) -> update();
      if (temp)
      {
        check = true;
      }
    }
  }
  else
  {
    cout << "Ready for takeoff? " << count_down << "..." << endl;
    cout << "Blast Off! You Win!" << endl;
    exit(0);
  }

  return check;
}

void Model::show_status()
{
  cout << "Time: " << timer << endl;
  for (list <Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
  {
    (*it) -> show_status();
  }
}

void Model::display(View& view)
{
  view.clear();

  for (list <Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
  {
      view.plot((*it));
  }

  view.draw();
}

void Model::handle_new_command()
{
  char type;
  int id, x, y;

  cin >> type >> id >> x >> y;
  if (cin.fail())
  {
    throw Invalid_Input("Please enter the type (char), ID (int), and x and y coordinates (int).");
  }

  Cart_Point pt = Cart_Point(x,y);
  switch (type)
  {
    case 'd':
    {
      for (list <Oxygen_Depot*>::iterator it = depot_ptrs.begin(); it != depot_ptrs.end(); ++it)
      {
        if((*it) -> get_id() == id)
        {
          throw Invalid_Input("ID number already exists.");
        }
      }
      Oxygen_Depot* ptrD = new Oxygen_Depot(pt, id);
      depot_ptrs.push_back(ptrD);
      object_ptrs.push_back(ptrD);
      active_ptrs.push_back(ptrD);
      break;
    }
    case 's':
    {
      for (list <Space_Station*>::iterator it = station_ptrs.begin(); it != station_ptrs.end(); ++it)
      {
        if((*it) -> get_id() == id)
        {
          throw Invalid_Input("ID number already exists.");
        }
      }
      Space_Station* ptrS = new Space_Station(pt, id);
      station_ptrs.push_back(ptrS);
      object_ptrs.push_back(ptrS);
      active_ptrs.push_back(ptrS);
      break;
    }
    case 'a':
    {
      for (list <Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
      {
        if((*it) -> get_id() == id)
        {
          throw Invalid_Input("ID number already exists.");
        }
      }
      Astronaut* ptrA = new Astronaut(id, pt);
      person_ptrs.push_back(ptrA);
      object_ptrs.push_back(ptrA);
      active_ptrs.push_back(ptrA);
      break;
    }
    case 'x':
    {
      for (list <Alien*>::iterator it = alien_ptrs.begin(); it != alien_ptrs.end(); ++it)
      {
        if((*it) -> get_id() == id)
        {
          throw Invalid_Input("ID number already exists.");
        }
      }
      Alien* ptrX = new Alien(id, pt);
      alien_ptrs.push_back(ptrX);
      object_ptrs.push_back(ptrX);
      active_ptrs.push_back(ptrX);
      break;
    }
    default:
      throw Invalid_Input("Invalid type. Enter 'd', 's', 'a', or 'x'.");
      break;
  }
}
