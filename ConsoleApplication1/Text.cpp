#include "stdafx.h"
#include "Text.h"
#include <iostream>

Text::Text()
{
	std::cout << "Constructor. Text." << std::endl;
}

Text::Text(const std::string text)
{
	std::cout << "Constructor. Text. " << text << std::endl;

	m_text = text;
}

Text::~Text()
{
	std::cout << "Destructor. Text." << std::endl;
}

void Text::draw()
{
	std::cout << "Draw Text." << std::endl;
}

std::string Text::getText() const
{
	return m_text;
}

void Text::setText(const std::string text)
{
	m_text = text;
}

void Text::printToStream(std::ostream & os) const
{
	os << "Print Text.";
}
