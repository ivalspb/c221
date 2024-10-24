#pragma once
#include <array>
#include <optional>

template <typename T, size_t N>
std::optional<T> my_ar_get(const std::array<T, N>& ar, size_t i)
{
	if (i < 0 || i >= N) 
		return std::nullopt;
	return ar[i];
}