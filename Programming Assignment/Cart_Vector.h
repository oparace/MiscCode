
#include "Cart_Point.h"
#include <iostream>
#ifndef CART_VECTOR_H
#define CART_VECTOR_H
class Cart_Point;


class Cart_Vector
{
	public:
		double x;
		double y;

		Cart_Vector();
		Cart_Vector(double,double);

};

Cart_Vector operator*(const Cart_Vector&, const double);
Cart_Vector operator/(const Cart_Vector&, const double);
std::ostream& operator<< (std::ostream&, const Cart_Vector&);

#endif


