#pragma once
#include <utility>

template <typename T>
T& my_sum(T&& s1, T&& s2)
{
	return std::forward<T>(s1) + std::forward<T>(s2);
}

template<typename T>
struct my_multiply
{
	T& operator()(const T& m1, const T& m2)
	{
		return m1 * m2;
	}
};