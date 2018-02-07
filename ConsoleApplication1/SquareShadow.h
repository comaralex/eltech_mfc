#pragma once
#include "Square.h"
#include "Color.h"

class SquareShadow : public Square
{
public:
	SquareShadow();
	SquareShadow(const int edge, const Coloryte coloryte);
	virtual ~SquareShadow();

	void draw() override;
	
	Color getShadowColor() const;
	void setShadowColor(const Color color);
	void setShadowColor(const Coloryte color);
	void setShadowColor(const int r, const int g, const int b);

protected:
	virtual void printToStream(std::ostream & os) const;

protected:
	Color m_shadowColor;
};

