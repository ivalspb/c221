#pragma once

template <typename T, typename... Types>
bool InRange(T&& min, T&& max, Types&&... args)
{
	return ((args<max && args>min)&&...);
}