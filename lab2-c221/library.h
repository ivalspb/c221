#pragma once
#include "book.h"
#include <list>
#include <map>

template <typename T=book>
class library
{
	std::map<T&&, size_t> lb;
public:
	library() = default;
	template <typename U=book, typename... Types>
	library(U&& b1, Types&&... books)
	{
		lb[std::forward<U>b1]++;
		if constexpr (sizeof...(books) > 0)
			library<Types>(std::forward<Types>(books));
	}
};

