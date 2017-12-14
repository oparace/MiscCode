#include <iostream>
#include "View.h"
#include <iomanip>
using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	origin.x = 0;
	origin.y = 0;
}


View::~View()
{
	std::cout<< "View destructed."<<endl;
}


void View::clear()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(Game_Object * ptr)
{
	int x;
	int y;
	char objectName[2];

	if(get_subscripts(x, y, ptr->get_location()))
	{
		ptr->drawself(objectName);

		if (grid[y][x][0] != '.')
		{
			grid[y][x][0] = '*';
			grid[y][x][1] = ' ';
		}
		else
		{
			grid[y][x][0] = objectName[0];
			grid[y][x][1] = objectName[1];
		}
	}
}


void View::draw()
{

	for (int i = view_maxsize; i >= 0; i -= 2*scale)
	{
		std::cout << std::left << std::setw(2) << i;

		for(int j = 0; j < size; j++)
		{
			std::cout << grid[i/2][j][0];
			std::cout << grid[i/2][j][1];
		}

		std::cout << endl;

		if (i!= 0)
		{
			for(int j = 0; j < size; j++)
			{
				std::cout << grid[(i/2 - 1)][j][0];
				std::cout << grid[(i/2 - 1)][j][1];
			}
			std::cout << endl;
		}

	}

	for (int i = 0; i <= view_maxsize; i += 4)
	{
		std::cout << std::left << std::setw(4) << i;
	}

	std::cout << endl;
	
	

}


bool View::get_subscripts(int& ix, int& iy , Cart_Point location)
{
	ix = (location.x - origin.x) / scale;
	iy = (location.y - origin.y) / scale;


	if (ix > size || iy > size)
	{
		std::cout << "An object is outside the display."<<endl;
		return false;
	}

	return true;
}
