#pragma once
#include <utility>
#include <iostream>

template <typename T>
class Point
{
	T x, y;
public:
	Point() = default;
	Point(const T& x, const T& y) : x(x), y(y) {};
	Point(T&& x, T&& y) : x(std::move(x)), y(std::move(y)) {};
	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		os << "(" << obj.x << "," << obj.y << ")";
		return os;
	};
};
