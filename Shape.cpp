#include "Shape.h"
#include <sstream>
#include "string.h"

int Shape::GetCount()
{
	return m_shapesNumber;
}

int Shape::m_shapesNumber = 0;

/*********************************************************/

Point::Point()
{
}

Point::Point(float x, float y)
{
	m_x = x;
	m_y = y;
	++m_shapesNumber;
}

std::string Point::GetInfo() const
{
	std::stringstream sStream;
	sStream << "Point, x=" << this->m_x << " y=" << this->m_y;
	return sStream.str();
}

/*********************************************************/

Circle::Circle(Point const & center, float r)
{
	m_center = center;
	m_r = r;
	++m_shapesNumber;
}

std::string Circle::GetInfo() const
{
	std::stringstream sStream;
	sStream << "Circle, center=" << this->m_center.GetInfo() << " y=" << this->m_r;
	return sStream.str();
}

/*********************************************************/

Rectangle::Rectangle(Point const & topLeft, Point const & bottomRight)
{
	m_topLeft = topLeft;
	m_bottomRight = bottomRight;
	++m_shapesNumber;
}

std::string Rectangle::GetInfo() const
{
	std::stringstream sStream;
	sStream << "Rectangle, topLeft=" << this->m_topLeft.GetInfo() << " bottomRight=" << this->m_bottomRight.GetInfo();
	return sStream.str();
}

/*********************************************************/

Square::Square(Point const & topLeft, float a)
{
	m_topLeft = topLeft;
	m_a = a;
	++m_shapesNumber;
}

std::string Square::GetInfo() const
{
	std::stringstream sStream;
	sStream << "Square, topLeft=" << this->m_topLeft.GetInfo() << " a=" << this->m_a;
	return sStream.str();
}

/*********************************************************/

Polyline::Polyline()
{
	m_points = Container<Point>();
	++m_shapesNumber;
}

void Polyline::AddPoint(Point const & point)
{
	m_points.AddLast(point);
}

std::string Polyline::GetInfo() const
{
	std::stringstream sStream;
	sStream << "Polyline,";
	for (int i = 0; i < this->m_points.GetNumberOfElements(); ++i)
	{
		sStream << " point[" << i << "]=" << (this->m_points.GetElement(i))->GetInfo() << ",";
	}
	return sStream.str();
}

