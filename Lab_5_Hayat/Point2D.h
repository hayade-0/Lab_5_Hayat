#include<iostream>
#include<string>
using namespace std;

class Point2D

{
public:
	float x;
	float y;
	Point2D()
	{
		x = 0;
		y = 0;
	}
	Point2D(float initA, float initB)
	{
		x = initA;
		y = initB;
	}
	Point2D(const Point2D& p)
	{
		x=p.x;
		y = p.y;

	}
	float distance_to(Point2D second) const;
	string toString();
	Point2D operator+ (const Point2D& second);
	void operator=(const Point2D ref);
	void print();




};

