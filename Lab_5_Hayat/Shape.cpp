/*#include<iostream>
#include<vector>
#include "Shape.h"
using namespace std;

void Shape::Renderer()
{
}

Point2D Shape::getPositionPOint()
{
	return this->positionPoint;
}

void Rectangle::Renderer()
{
	Point2D recPosition = getPositionPOint();
	cout << "Rectangle " << recPosition.toString() << " width: " << width << " Height: " << height << endl;
}

void Triangle::Renderer()
{
	Point2D triPosition = getPositionPOint();
	cout << "Triangle " << triPosition.toString() << " base: " << base << " Height: " << height << endl;

}

void Circle::Renderer()
{
	Point2D cirPosition = getPositionPOint();
	cout << "Circle " << cirPosition.toString() << " Radius: " << radius << endl;

}
void testRendering(Shape* Shape)
{
	Shape->Renderer();
}
  int main()
{
	vector<Shape*> shapeVector;
	Point2D rectanglePosition(50, 24.4);
	float rectangleWidht = 124.5;
	float rectangleHeight = 100.4;
	int rectangleColor[] = { 255,0,0,255 };
	Rectangle testOne(rectanglePosition, rectangleColor, rectangleWidht, rectangleHeight);
	shapeVector.push_back(&testOne);
	Point2D trianglePosition(74,39.7);
	float triangleBase = 115;
	float triangleHeight = 231;
	int triangleColor[] = { 0,255,0,255 };
	Triangle testTwo(trianglePosition, triangleColor, triangleBase, triangleHeight);
	shapeVector.push_back(&testTwo);
	Point2D circlePosition(150, 255);
	float circleRadius = 50;
	int circleColor[] = { 0,0,255,255 };
	Circle testThree (circlePosition, circleColor, circleRadius);
	shapeVector.push_back(&testThree);
	for (int i = 0; i < shapeVector.size(); i++)
		testRendering(shapeVector[i]);
}*/
