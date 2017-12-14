

#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"

Cart_Vector::Cart_Vector()
{
	x = 0;
	y = 0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

Cart_Vector operator*(const Cart_Vector& v1, double const d)
{
	Cart_Vector Point2(v1.x * d, v1.y * d);
	return Point2;
}

Cart_Vector operator/(const Cart_Vector& v1, double const d)
{
	if (d != 0)
	{
		Cart_Vector Point2(v1.x / d, v1.y / d);
		return Point2;
	}

	else
	{
		return v1;
	}
}


std::ostream& operator<< (std::ostream& outStream, const Cart_Vector& v1)
{
	return outStream << "<" << v1.x << "," << v1.y << ">";
}
