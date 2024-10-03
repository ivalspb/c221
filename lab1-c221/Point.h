#pragma once

template <typename T>
class Point
{
	T x, y;
public:
	Point(const T& x, const T& y) : x(x), y(y) {}
	Point(T&& x, T&& y) : x(std::move(x)), y(std::move(y)) {}
};
