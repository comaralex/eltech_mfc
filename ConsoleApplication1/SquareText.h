#pragma once
#include "Square.h"
#include "Text.h"

class SquareText : public Square, public Text
{
public:
	SquareText();
	SquareText(const std::string text, const int edge);
	virtual ~SquareText();

	void draw() override;

protected:
	virtual void printToStream(std::ostream & os) const;
};

