#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "Astronaut.h"


const int view_maxsize = 20;

class View
{
public:
	View();
	~View();
	void clear();
	void plot(Game_Object * ptr);
	void draw();

private:
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];

	bool get_subscripts(int&, int&, Cart_Point);
};


#endif
