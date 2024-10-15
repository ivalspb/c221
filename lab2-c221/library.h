#pragma once
#include "book.h"
#include <list>
#include <map>

class library
{
	std::map<book&, size_t> lb;
public:
	library() = default;
	
	template <typename... Types>
	library(Types&&... args)
	{
		if constexpr (sizeof...(args) > 0)
			(lb[std::forward<Types>(args)]++, ...);
	}

	/*template <book& b1, book&... Types>
	library(const book& b1, const Types books)
	{
		lb[b1]++;
		if constexpr (sizeof...(books) > 0)
			library<Types>(books...);
	}*/
};

