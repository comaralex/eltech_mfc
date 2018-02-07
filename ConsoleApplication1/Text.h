#pragma once
#include <string>
#include "Shape.h"
class Text : virtual public Shape
{
public:
	Text();
	Text(const std::string text);
	virtual ~Text();

	void draw() override;
	
	std::string getText() const;
	void setText(const std::string text);

protected:
	virtual void printToStream(std::ostream & os) const;

protected:
	std::string m_text;
};

