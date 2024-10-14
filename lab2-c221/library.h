#pragma once
#include "book.h"
#include <list>
#include <map>

class library
{
	std::map<book&, size_t> lb;
public:
	library() = default;

};

