#pragma once
#include <string>
#include <iostream>

class cat
{
	std::string name;
public:
	cat() = default;
	template <typename T>
	cat(T&& n) :name(std::forward<T>(n)){}
	friend std::ostream& operator<<(std::ostream& os, const cat& c)
	{
		os << "Cat " << c.name << std::endl;
		return os;
	}
};

