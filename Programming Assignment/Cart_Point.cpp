

#include "Cart_Point.h"

Cart_Point::Cart_Point()
{
	x = 0;
	y = 0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
	
    double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));


	return distance;
}


std::ostream& operator<< (std::ostream &outStream, const Cart_Point& p1)
{
	return outStream << "(" << p1.x << "," << p1.y << ")";
}

Cart_Point operator+(const Cart_Point &p1, const Cart_Vector &v1)
{
	Cart_Point Point(p1.x + v1.x, p1.y + v1.y);
	return Point;
}

Cart_Vector operator-(const Cart_Point &p1, const Cart_Point &p2)
{
	Cart_Vector Point1(p1.x - p2.x, p1.y - p2.y);
	return Point1;
}


