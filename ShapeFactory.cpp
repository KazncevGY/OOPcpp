#include "ShapeFactory.h"

Point * getRandomPoint(float maxX, float maxY)
{

	float x, y;
	x = maxX / (rand() % (int)maxX + 1);
	y = maxY / (rand() % (int)maxY + 1);
	return new Point(x, y);
}

Circle * getRandomCircle(float maxX, float maxY, float maxR)
{

	float x, y, r;
	x = maxX / (rand() % (int)maxX + 1);
	y = maxY / (rand() % (int)maxY + 1);
	r = maxR / (rand() % (int)maxR + 1);
	return new Circle(Point(x, y), r);
}

Rectangle * getRandomRectangle(float maxX, float maxY)
{

	float x1, x2, y1, y2;
	x1 = maxX / (rand() % (int)maxX + 1);
	y1 = maxY / (rand() % (int)maxY + 1);
	x2 = maxX / (rand() % (int)maxX + 1);
	y2 = maxY / (rand() % (int)maxY + 1);
	if (x1 < x2)
	{
		float buffer = x1;
		x1 = x2;
		x2 = buffer;
	}

	if (y1 > y2)
	{
		float buffer = y1;
		y1 = y2;
		y2 = buffer;
	}
	return new Rectangle(Point(x1, y1), Point(x2, y2));
}

Square * getRandomSquare(float maxX, float maxY, float maxA)
{

	float x, y, a;
	x = maxX / (rand() % (int)maxX + 1);
	y = maxY / (rand() % (int)maxY + 1);
	a = maxA / (rand() % (int)maxA + 1);
	return new Square(Point(x, y), a);
}

Polyline * getRandomPolyline(float maxX, float maxY, int maxNumber)
{

	Polyline * newPolyline = new Polyline();
	int pointsNumber = (rand() % maxNumber + 1);
	for (int i = 0; i < pointsNumber; ++i)
	{
		float x, y;
		x = maxX / (rand() % (int)maxX + 1);
		y = maxY / (rand() % (int)maxY + 1);
		newPolyline->AddPoint(Point(x, y));
	}
	return newPolyline;
}