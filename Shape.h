#include "Container.h"
#include "Base.h"

#pragma once

class Shape : public Printable
{
public:
	static int GetCount();
	virtual std::string GetInfo() const = 0;
	~Shape() { --m_shapesNumber; }
protected:
	static int m_shapesNumber;
};

class Point : public Shape
{
public:
	Point();
	Point(float x, float y);
	std::string GetInfo() const;
	std::ostream & operator << (std::ostream & ioStream) { ioStream << this->GetInfo(); }
private:
	float m_x;
	float m_y;
};




class Circle : public Shape
{
public:
	Circle(Point const & center, float r);
	std::string GetInfo() const;
	std::ostream & operator << (std::ostream & ioStream) { ioStream << this->GetInfo(); }
private:
	Point m_center;
	float m_r;
};

class Rectangle : public Shape
{
public:
	Rectangle(Point const & leftTop, Point const & rigthBottom);
	std::string GetInfo() const;
	std::ostream & operator << (std::ostream & ioStream) { ioStream << this->GetInfo(); }
private:
	Point m_topLeft;
	Point m_bottomRight;
};

class Square : public Shape
{
public:
	Square(Point const & leftTop, float a);
	std::string GetInfo() const;
	std::ostream & operator << (std::ostream & ioStream) { ioStream << this->GetInfo(); }
private:
	Point m_topLeft;
	float m_a;
};

class Polyline : public Shape
{
public:
	Polyline();
	void AddPoint(Point const & point);
	std::string GetInfo() const;
	std::ostream & operator << (std::ostream & ioStream) { ioStream << this->GetInfo(); }
private:
	Container<Point> m_points;
};

