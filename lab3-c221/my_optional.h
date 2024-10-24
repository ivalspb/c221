#pragma once
#include <optional>
#include <vector>
#include "Shape.h"

template <typename T>
std::optional<size_t> get_index_by_abs_value(std::vector<T>& v, T&& val)
{
	for (size_t i = 0; i < v.size(); i++)
		if (abs(std::forward<T>(val)) == abs(v[i]))
			return { i };
	return std::nullopt;
}

struct Prn_V_CLR
{
	void operator()(auto x)const { std::cout << " " << x << " "; }
	void operator()(Color x)const 
	{
		switch (x)
		{
		case Red:
			std::cout << " RED ";
			break;
		case Green:
			std::cout << " GREEN ";
			break;
		case Blue:
			std::cout << " BLUE ";
			break;
		default:
			break;
		}
	}
};