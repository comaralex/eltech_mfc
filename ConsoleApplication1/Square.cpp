#include "stdafx.h"
#include "Square.h"
#include <iostream>

Square::Square() :
	Shape(),
	m_edge(DEFAULT_EDGE)
{
	std::cout << "Constructor. Square." << std::endl;
}

Square::Square(const int edge)
{
	std::cout << "Constructor. Square. " << edge << std::endl;

	m_edge = edge;
}

Square::~Square()
{
	std::cout << "Destructor. Square." << std::endl;
}

void Square::draw()
{
	std::cout << "Draw Square." << std::endl;
}

int Square::getEdge() const
{
	return m_edge;
}

void Square::setEdge(const int edge)
{
	m_edge = edge;
}

void Square::printToStream(std::ostream & os) const
{
	os << "Print Square.";
}

