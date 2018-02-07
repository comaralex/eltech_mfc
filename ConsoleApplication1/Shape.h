#pragma once
#include <string>
#include <ostream>

#define DEFAULT_X 0
#define DEFAULT_Y 0

class Shape
{
public:
	Shape();
	Shape(const int x, const int y);
	virtual ~Shape();

	virtual void draw() = 0;
	virtual void move(const int x, const int y);

	friend std::ostream & operator<<(std::ostream & os, const Shape & s);

protected:
	virtual void printToStream(std::ostream & os) const = 0;

protected:
	int m_x;
	int m_y;
};