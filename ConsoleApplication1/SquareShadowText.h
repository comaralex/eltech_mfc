#pragma once
#include "SquareShadow.h"
#include "Text.h"

class SquareShadowText : public SquareShadow, public Text
{
public:
	SquareShadowText();
	SquareShadowText(const std::string text, const int edge, const Coloryte coloryte);
	virtual ~SquareShadowText();

	void draw() override;

protected:
	virtual void printToStream(std::ostream & os) const;
};

