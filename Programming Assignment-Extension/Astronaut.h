//STEP 7: Astronauts can now attack aliens; their speed changes randomly with gravity

#ifndef ASTRONAUT
#define ASTRONAUT

#include "Person.h"
#include <stdio.h>
#include <ctype.h>

using namespace std;

class Astronaut : public Person
{
public:
  Astronaut();
  Astronaut(int, Cart_Point);
  ~Astronaut();

  bool update();
  void start_supplying(Oxygen_Depot*);
  void start_depositing(Space_Station*);
  void go_to_station(Space_Station*);
  void show_status();

  bool there;

private:
  double amount_moonstones;
  double amount_oxygen;
  Oxygen_Depot* depot;
  Space_Station* home;
};

#endif
