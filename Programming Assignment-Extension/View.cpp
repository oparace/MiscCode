#include <iostream>
#include "View.h"

using namespace std;

View::View()
{
  size = 11;
  scale = 2;
  origin = Cart_Point();
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
  Cart_Vector sub = (location - origin);
  sub = sub/scale;
  sub.x = (int) sub.x; 
  sub.y = (int) sub.y;

  if (sub.x <= size*scale && sub.y <= size*scale)
  {
    ix = sub.x;
    iy = sub.y;
    return true;
  }
  else
  {
    cout << "An object is outside the display" << endl;
    return false;
  }
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

void View::plot(Game_Object* ptr)
{
  int x, y;
  bool valid = get_subscripts(x, y, ptr -> get_location());

  if (valid)
  {
    if( grid[x][y][0] != '.' )
    {
      grid[x][y][0] = '*';
      grid[x][y][1] = ' ';
    }
    else
    {
      char* chardisp = new char;
      ptr -> drawself(chardisp);
      grid[x][y][0] = *chardisp;
      grid[x][y][1] = *(chardisp+1);
      delete chardisp;
    }
  }
}

void View::draw()
{
  for (int y = size - 1; y >= 0; y--)
  {
    if(!(y % 2))
    {
      if (y*scale < 10)
      {
        cout << y * scale << " ";
      }
      else
      {
        cout << y * scale;
      }
    }
    else
    {
      cout << "  ";
    }
    for (int x = 0; x < size; x++)
    {
      cout << grid[x][y][0] << grid[x][y][1];
    }
    cout << endl;
  }


  
  cout << "  ";
  for (int x = 0; x < size; x++)
  {
    if (!(x % 2))
    {
      if (x*scale < 10)
      {
        cout << x * scale << " ";
      }
      else
      {
        cout << x * scale;
      }
    }
    else
    {
      cout << "  ";
    }
  }

  cout << endl;
}
