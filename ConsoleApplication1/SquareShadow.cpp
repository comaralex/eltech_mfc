#include "stdafx.h"
#include "SquareShadow.h"
#include <iostream>

SquareShadow::SquareShadow() :
	Square()
{
	std::cout << "Constructor. SquareShadow." << std::endl;
}

SquareShadow::SquareShadow(const int edge, const Coloryte coloryte) :
	Square(edge)
{
	std::cout << "Constructor. SquareShadow. "
		<< coloryte.m_r << " "
		<< coloryte.m_g << " "
		<< coloryte.m_b << std::endl;

	m_shadowColor = Color(coloryte);
}

SquareShadow::~SquareShadow()
{
	std::cout << "Destructor. SquareShadow." << std::endl;
}

void SquareShadow::draw()
{
	std::cout << "Draw SquareShadow." << std::endl;
}

Color SquareShadow::getShadowColor() const
{
	return m_shadowColor;
}

void SquareShadow::setShadowColor(const Color color)
{
	m_shadowColor = color;
}

void SquareShadow::setShadowColor(const Coloryte color)
{
	m_shadowColor = Color(color);
}

void SquareShadow::setShadowColor(const int r, const int g, const int b)
{
	m_shadowColor = Color(r, g, b);
}

void SquareShadow::printToStream(std::ostream & os) const
{
	os << "Print SquareShadow.";
}
