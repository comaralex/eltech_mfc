#include "stdafx.h"
#include "SquareText.h"
#include <iostream>

SquareText::SquareText()
	: Square(), Text()
{
	std::cout << "Constructor. SquareText." << std::endl;
}

SquareText::SquareText(const std::string text, const int edge)
	: Square(edge), Text(text)
{
	std::cout << "Constructor. SquareText." << std::endl;
}

SquareText::~SquareText()
{
	std::cout << "Destructor. SquareText." << std::endl;
}

void SquareText::draw()
{
	std::cout << "Draw SquareText." << std::endl;

}

void SquareText::printToStream(std::ostream & os) const
{
	os << "Print SquareText"
		<< " text=" << getText()
		<< " edge=" << getEdge();
}

