#pragma once
#include <iostream>
#include "Color.h"

class ColoredRect
{
	Color m_col;
	int m_x, m_y, m_h, m_w;
public:
	ColoredRect() = default;
	ColoredRect(const Color c, const int x, const int y, const int h, const int w) :m_col(c), m_x(x), m_y(y), m_h(h), m_w(w) {}
	Color getColor() const;
	double getSquare() const;
	
	auto operator<=>(const ColoredRect& other) const = default;

	friend std::ostream& operator<<(std::ostream& os, const ColoredRect& c);
};



