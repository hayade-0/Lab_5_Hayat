#include<iostream>
#include<math.h>
#include "Point2D.h"
using namespace std ;

float Point2D::distance_to(Point2D second) const 
{
	float distance = sqrt(pow((this->x - second.x), 2) + pow((this->y - second.y), 2));
	return distance;
}

string Point2D::toString()
{
	string strPoint = "[";
	strPoint += to_string(x);
	strPoint += " , ";
	strPoint += to_string(y);
	strPoint += "]";

	return strPoint;
}
Point2D Point2D::operator+(const Point2D& second)
{
	Point2D pointHolder;
	pointHolder.x = this->x + second.x;
	pointHolder.y = this->y + second.y;
	return pointHolder;
}
void Point2D::operator=(const Point2D ref)
{
	x = ref.x;
	y = ref.y;
}
void Point2D::print()
{
	cout << toString() << endl;
}
/*
int main()
{
	Point2D pointone;
	pointone.x = 2.5;
	pointone.y = 3.1;
	Point2D pointTwo;
	pointTwo.x = 7.1;
	pointTwo.y = 2.4;
	cout << "the distance between the two points: " << pointone.distance_to(pointTwo) << endl;
	Point2D pointThree =pointone;
	pointThree.print();
	Point2D pointfour = pointone + pointTwo;
	pointfour.print();
	cout << "the distance between the new point and first point: " << pointfour.distance_to(pointone) << endl;
	Point2D pointfive = pointone;
	pointfive.print();


}
*/

