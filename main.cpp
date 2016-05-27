//#include "Container.h"
#include "ShapeFactory.h"
#include <iostream>


void main()
{
	srand((unsigned int)(time(NULL)));
	Container<Shape *> container = Container<Shape *>();
	for (int i = 0; i < 5; ++i)
	{
		container.AddFirst(getRandomCircle(100, 200, 20));
	}
	for (int i = 0; i < 5; ++i)
	{
		container.AddLast(getRandomSquare(100, 200, 20));
	}
	for (int i = 0; i < 5; ++i)
	{
		container.AddFirst(getRandomPoint(100, 200));
	}
	for (int i = 0; i < 5; ++i)
	{
		container.AddFirst(getRandomRectangle(100, 200));
	}
	for (int i = 0; i < 5; ++i)
	{
		container.AddFirst(getRandomPolyline(100, 200, 7));
	}
	std::cout << Shape::GetCount() << std::endl;
	for (int i = 0; i < Shape::GetCount(); ++i)
	{
		std::cout << (*(container.GetElement(i)))->GetInfo() << std::endl;
	}
	container.Clear();
	std::cout << Shape::GetCount();
}