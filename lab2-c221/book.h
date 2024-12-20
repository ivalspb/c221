#pragma once
#include <tuple>
#include <string>
#include <utility>
#include <iostream>
#include "tuple_print.h"

class book
{
	std::tuple<std::string, std::string, size_t> data{};//author,title,year
public:
	book() = default;
	book(const std::string& author, const std::string& title, size_t year) : data(author, title, year) {}

	std::string get_author() const { return std::get<0>(data); }
	std::string get_title() const { return std::get<1>(data); }
	size_t get_year() const { return std::get<2>(data); }

	auto operator<=>(const book& other) const = default;
	
	friend std::ostream& operator<<(std::ostream& os, const book& b);

};

