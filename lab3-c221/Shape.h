#pragma once
#include <compare>
#include <iostream>

static enum Color { Red, Green, Blue };

static const char* color_s[]={ "Red","Green","Blue" };

class Shape
{
	Color c=Color::Red;
public:
	Shape() = default;
	Shape(const Color& c) :c(c) {}
	virtual void setClr(const Color& new_clr);

	virtual size_t getSq() const =0;
	virtual Color Clr() const;
	virtual std::strong_ordering  operator<=>(const Shape& other) const noexcept = default;
	friend std::ostream& operator<<(std::ostream& os, const Shape& s);
};
