#include<vector>
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include<math.h>
#include"Drawing_Shapes.h"
#include <algorithm>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void Shape::Renderer(SDL_Renderer* shapeRenderer)
{
	cout << " you shouldnt supposed to see this" << endl;
}

int Shape::getColor(int index)
{
	return colorArray[index];
}

Point2D Shape::getPositionPOint()
{
	return this->positionPoint;
}

void Rectangle::Renderer(SDL_Renderer* shapeRenderer)
{
	Point2D recPosition = getPositionPOint();
	cout << "Rectangle " << recPosition.toString() << " width: " << width << " Height: " << height << endl;
	SDL_SetRenderDrawColor(shapeRenderer, getColor(0), getColor(1), getColor(2), getColor(3));
	SDL_RenderDrawLine(shapeRenderer,recPosition.x,recPosition.y, recPosition.x + width,recPosition.y);
	SDL_RenderDrawLine(shapeRenderer, recPosition.x, recPosition.y, recPosition.x,recPosition.y + height);
	SDL_RenderDrawLine(shapeRenderer, recPosition.x,recPosition.y + height, recPosition.x + width, recPosition.y + height);
	SDL_RenderDrawLine(shapeRenderer, recPosition.x + width, recPosition.y + height,recPosition.x + width, recPosition.y);
	//SDL_RenderPresent(shapeRenderer);
	//SDL_Delay(8000);

}

void Triangle::Renderer(SDL_Renderer* shapeRenderer)
{
	Point2D triPosition = getPositionPOint();
	cout << "Triangle " << triPosition.toString() << " base: " << base << " Height: " << height << endl;
	SDL_SetRenderDrawColor(shapeRenderer, getColor(0), getColor(1), getColor(2), getColor(3));
	SDL_RenderDrawLine(shapeRenderer, triPosition.x, triPosition.y, triPosition.x, triPosition.y + height);
	SDL_RenderDrawLine(shapeRenderer, triPosition.x, triPosition.y + height, triPosition.x + base, triPosition.y + height);
	SDL_RenderDrawLine(shapeRenderer, triPosition.x + base, triPosition.y + height, triPosition.x, triPosition.y);
	//SDL_RenderPresent(shapeRenderer);
	//SDL_Delay(8000);
}

void Circle::Renderer(SDL_Renderer* shapeRenderer)
{
	Point2D cirPosition = getPositionPOint();
	float angleTheta =0;
	float x_center = cirPosition.x;
	float y_center = cirPosition.y;
	float newX=0;
	float newY=0;
	int angleIncrement=10;
	cout << "Circle " << cirPosition.toString() << " Radius: " << radius << endl;
	SDL_SetRenderDrawColor(shapeRenderer, getColor(0), getColor(1), getColor(2), getColor(3));
	while(angleTheta<=360)
	{
		newX = x_center + radius * cos(angleTheta);
		newY = y_center + radius * sin(angleTheta);
		SDL_RenderDrawLine(shapeRenderer, x_center, y_center, newX, newY);
		angleTheta += angleIncrement;
	}
	//SDL_RenderPresent(shapeRenderer);
	//SDL_Delay(8000);

}
void testRendering(Shape* Shape,SDL_Renderer* shapeRenderer)
{
	  Shape->Renderer(shapeRenderer);
}

/*
int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* shapeRenderer = NULL;
	shapeRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(shapeRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(shapeRenderer);
	vector<Shape*> shapeVector;
	Point2D rectanglePosition(50, 24.4);
	float rectangleWidht = 124.5;
	float rectangleHeight = 100.4;
	int rectangleColor[] = { 255,0,0,255 };
	Rectangle testOne(rectanglePosition, rectangleColor, rectangleWidht, rectangleHeight);
	shapeVector.push_back(&testOne);
	Point2D trianglePosition(74, 39.7);
	float triangleBase = 115;
	float triangleHeight = 231;
	int triangleColor[] = { 0,255,0,255 };
	Triangle testTwo(trianglePosition, triangleColor, triangleBase, triangleHeight);
	shapeVector.push_back(&testTwo);
	Point2D circlePosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	float circleRadius = 50;
	int circleColor[] = { 0,255,255,255 };
	Circle testThree(circlePosition, circleColor, circleRadius);
	shapeVector.push_back(&testThree);
	for (int i = 0; i < shapeVector.size(); i++)
	{
		testRendering(shapeVector[i], shapeRenderer);
		SDL_SetRenderDrawColor(shapeRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(shapeRenderer);
	}
	return 0;
}*/
int main(int argc, char* args[])
{
	int index = 0;
	bool active = true;
	int initX;
	int initY;
	Point2D circlePosition;
	int circleColor[4] = { 0,255,255,255 };
	int circleRadius;
	float triangleBase;
	float triangleHeight;
	int triangleColor[] = { 0,255,0,255 };
	float rectangleWidht;
	float rectangleHeight;
	int rectangleColor[] = { 255,0,0,255 };
	Point2D trianglePosition;
	SDL_Init(SDL_INIT_VIDEO);
	vector <Shape>  shapeVector;
	//cout << "SHAPE DISPLAYINH GAME\nYou want to creat?:\nCircle: press c\nTriangle: press t\nRectangle: press R\n To Quit:pressq";
	//cout << "\nTo removing saved shape press x" << endl;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout<<stderr<<"Could not initialise SDL: %s\n"<<SDL_GetError()<<endl;
		exit(-1);
	}
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* shapeRenderer = NULL;
	shapeRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(shapeRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(shapeRenderer);
	while (active)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		while (SDL_PollEvent(&event))
		{
			if (event.type==SDL_KEYDOWN)
							switch (event.key.keysym.sym)
							{
							case SDLK_c:
							{
								
								initX = (rand() % (SCREEN_HEIGHT-40)) + 20;
								initY = (rand() % (500-40)) + 20;
								int maxBoundery = min({ initX, initY, 500 - 20 - initX, 400 - 20 - initY });
								circleRadius = (rand() % maxBoundery);
								circlePosition.x = initX;
								circlePosition.y = initY;
								
								Circle testThree(circlePosition, circleColor, circleRadius);
								
								(&testThree)->Renderer(shapeRenderer);
								cout << "c is pressed Press Next Key"<<endl;
								break;
							}
							case SDLK_t:
							{
								initX = (rand() % 400) + 1;
								initY = (rand() % 500) + 1;
								trianglePosition.x = initX;
								trianglePosition.y = initY;
								triangleBase = (rand() % (500 - initX - 20)) + 20;
								triangleHeight = (rand() % (400 - initY - 20)) + 20;;
								Triangle testTwo(trianglePosition, triangleColor, triangleBase, triangleHeight);
								(&testTwo)->Renderer(shapeRenderer);
								cout << " t is preesed Press Next Key" << endl;
								break;
							}
							case SDLK_r:
							{
								initX = (rand() % 300) + 1;
								initY = (rand() % 400) + 1;
								Point2D rectanglePosition(initX, initY);
								rectangleWidht = (rand() % (400 - initX - 20)) + 20;
								rectangleHeight = (rand() % (300 - initY - 20)) + 20;;
								Rectangle testOne(rectanglePosition, rectangleColor, rectangleWidht, rectangleHeight);
								(&testOne)->Renderer(shapeRenderer);
								cout << " r is Pessed Press Next Key"<<endl;
								break;
							}
							case SDLK_q:
							{
								SDL_RenderPresent(shapeRenderer);
								SDL_Delay(12000);
								active = false;
								break;
							}
							case SDLK_x:
								SDL_SetRenderDrawColor(shapeRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
								SDL_RenderClear(shapeRenderer);
								break;
							default:
								cout << "Error Please Press write key" << endl;
								break;
							}
						}
					}
	return 0;
}