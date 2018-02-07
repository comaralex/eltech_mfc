#include "stdafx.h"
#include "Shape.h"
#include <iostream>

Shape::Shape() :
	m_x(DEFAULT_X),
	m_y(DEFAULT_Y)
{
	std::cout << "Constructor. I am base class Shape." << std::endl;
}

Shape::Shape(const int x, const int y)
{
	m_x = x;
	m_y = y;
}

Shape::~Shape()
{
	std::cout << "Destructor. I am base class Shape." << std::endl;
}

void Shape::move(const int x, const int y)
{
	m_x = x;
	m_y = y;
}

//void Shape::draw()
//{
//	std::cout << "Draw in base class Shape." << std::endl;
//}

std::ostream & operator<<(std::ostream & os, const Shape & s)
{
	s.printToStream(os);
	return os;
}