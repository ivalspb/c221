#pragma once
#include <utility>

template <typename T>
T my_sum(T&& s1, T&& s2)
{
	return std::forward<T>(s1) + std::forward<T>(s2);
}

template<typename T>
struct my_multiply
{
	T operator()(const T& m1, const T& m2)
	{
		return m1 * m2;
	}
};

//template <typename T>
class my_compare
{
public:
	double operator()(const double& g1, const double& g2)
	{
		if (g1 > g2)
			return g1;
		else return g2;
	}
	double greater(const double& g1, const double& g2) const
	{
		if (g1 > g2) 
			return g1;
		else return g2;
	}
};