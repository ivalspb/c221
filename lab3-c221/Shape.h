#pragma once
#include <compare>
#include <iostream>

enum Color { Red, Green, Blue };

class Shape
{
	Color c;
public:
	Shape() = default;
	Shape(const Color& c) :c(c) {}
	virtual void setClr(const Color& new_clr);
	virtual Color Clr() const;
	virtual std::strong_ordering  operator<=>(const Shape& other) const = default;
	friend std::ostream& operator<<(std::ostream& os, const Shape& s);
};
