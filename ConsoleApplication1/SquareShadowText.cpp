#include "stdafx.h"
#include "SquareShadowText.h"
#include "Color.h"
#include <iostream>

SquareShadowText::SquareShadowText() :
	SquareShadow(), Text()
{
	std::cout << "Constructor. SquareShadowText." << std::endl;
}

SquareShadowText::SquareShadowText(const std::string text, const int edge, const Coloryte coloryte) :
	SquareShadow(edge, coloryte), Text(text)
{
}

SquareShadowText::~SquareShadowText()
{
	std::cout << "Destructor. SquareShadowText." << std::endl;
}

void SquareShadowText::draw()
{
	std::cout << "Draw SquareShadowText." << std::endl;
}

void SquareShadowText::printToStream(std::ostream & os) const
{
	os << "Print SquareShadowText"
		<< " text=" << getText()
		<< " edge=" << getEdge()
		<< " color="
		<< m_shadowColor.getR() << " "
		<< m_shadowColor.getG() << " "
		<< m_shadowColor.getB();
}
