

#ifndef CART_POINT_H
#define CART_POINT_H

#include <iostream>
#include <cmath>
class Cart_Vector;
#include "Cart_Vector.h"	

class Cart_Point
{

public:

	
	double x;
	double y;

	Cart_Point();
	Cart_Point(double, double);
};

double cart_distance(Cart_Point, Cart_Point);


Cart_Point operator+(const Cart_Point&, const Cart_Vector&);
Cart_Vector operator-(const Cart_Point&, const Cart_Point&);



std::ostream& operator<< (std::ostream&, const Cart_Point&);

#endif






