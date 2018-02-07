#pragma once
#include "Shape.h"

#define DEFAULT_EDGE 0

class Square : virtual public Shape
{
public:
	Square();
	Square(const int edge);
	virtual ~Square();

	void draw() override;

	int getEdge() const;
	void setEdge(const int edge);

protected:
	virtual void printToStream(std::ostream & os) const;

protected:
	//int width;
	//int height;
	int m_edge;
};

