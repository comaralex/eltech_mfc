#include "stdafx.h"
#include "Color.h"


Color::Color()
{
}

Color::Color(Coloryte coloryte)
{
	m_color = coloryte;
}

Color::Color(const int r, const int g, const int b)
{
	m_color.m_r = r;
	m_color.m_g = g;
	m_color.m_b = b;
}

Color::~Color()
{
}

int Color::getR() const
{
	return m_color.m_r;
}

int Color::getG() const
{
	return m_color.m_g;
}

int Color::getB() const
{
	return m_color.m_b;
}

void Color::setR(const int r)
{
	m_color.m_r = r;
}

void Color::setG(const int g)
{
	m_color.m_g = g;
}

void Color::setB(const int b)
{
	m_color.m_b = b;
}

Coloryte Color::getColor() const
{
	return m_color;
}

void Color::setColor(Coloryte color)
{
	m_color = color;
}

void Color::setColor(const int r, const int g, const int b)
{
	m_color.m_r = r;
	m_color.m_g = g;
	m_color.m_b = b;
}
