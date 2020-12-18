#include<iostream>
#include "Point2D.h"
using namespace std;
class Shape
{
private:
	Point2D positionPoint;
	int* colorArray;
public:
	Shape()
	{
		positionPoint.x = NULL;
		positionPoint.y = NULL;
		for (int i = 0; i < 4; i++)
			colorArray[i] = NULL;
	}
	Shape(Point2D position, int ColorArray[])
	{
		positionPoint = position;
		this->colorArray = new int[4];
		for (int i = 0; i < 4; i++)
			if (ColorArray[i] >= 0 && ColorArray[i] <= 255)
				this->colorArray[i] = ColorArray[i];
	}
	virtual void Renderer(SDL_Renderer* shapeRendere);
	Point2D getPositionPOint();
	int getColor(int index);

};
class Rectangle :public Shape {
public:
	float width;
	float height;
	Rectangle(Point2D position, int  ColorArray[4], float width, float height) :
		Shape(position, ColorArray), width(width), height(height) {}
	void Renderer(SDL_Renderer* shapeRendere);
};
class Triangle :public Shape {
public:
	float base;
	float height;
	Triangle(Point2D position, int ColorArray[4], float base, float height) :
		Shape(position, ColorArray), base(base), height(height) {}
	void Renderer(SDL_Renderer* shapeRendere);
};
class Circle :public Shape {
public:
	float radius;
	Circle(Point2D position, int ColorArray[4], float radius) :
		Shape(position, ColorArray), radius(radius) {}
	void Renderer(SDL_Renderer* shapeRendere);
}; 