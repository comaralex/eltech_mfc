#pragma once

#define DEFAULT_R 1
#define DEFAULT_G 2
#define DEFAULT_B 3

struct Coloryte {
	int m_r;
	int m_g;
	int m_b;

	Coloryte() {
		m_r = DEFAULT_R;
		m_g = DEFAULT_G;
		m_b = DEFAULT_B;
	}

	Coloryte(const int r, const int g, const int b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}
};

class Color
{
public:
	Color();
	Color(Coloryte coloryte);
	Color(const int r, const int g, const int b);
	~Color();

	int getR() const;
	int getG() const;
	int getB() const;
	void setR(const int r);
	void setG(const int g);
	void setB(const int b);
	Coloryte getColor() const;
	void setColor(Coloryte color);
	void setColor(const int r, const int g, const int b);

private:
	Coloryte m_color;
};






















#include <string>
const std::string comEnd = "Com9";