#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum Color {Red, Green, Blue};

class ColoredCircle
{
	Color m_col;
	int m_x, m_y, m_r;
public:
	ColoredCircle() = default;
	ColoredCircle(const Color c, const int x, const int y, const int r ):m_col(c),m_x(x),m_y(y),m_r(r){}
	Color getColor() const;
	double getSquare() const;
	int& Radius();
	//void setRadius(const int new_r);
	int& X();
	int& Y();

	double getDist() const;

	friend std::ostream& operator<<(std::ostream& os, const ColoredCircle& c);
};

