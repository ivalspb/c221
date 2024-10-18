#pragma once
#include <vector>
#include <string_view>

template <typename... Types>
std::vector<std::string_view> make_str_vec(Types&&... args)
{
	std::vector<std::string_view>s;
	((s.push_back(std::forward<Types>(args))),...);
	std::vector<std::string_view::iterator> space_iterators;
	/*for (std::string_view::iterator it = s.begin(); it != s.end(); ++it) 
	{
		if (*it == " ") space_iterators.push_back(it);
	}*/
	return s;
}
