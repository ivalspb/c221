#pragma once
#include <optional>
#include <vector>

template <typename T>
std::optional<size_t> get_index_by_abs_value(std::vector<T>& v, T&& val)
{
	for (size_t i = 0; i < v.size(); i++)
		if (abs(std::forward<T>(val)) == abs(v[i]))
			return { i };
	return std::nullopt;
}