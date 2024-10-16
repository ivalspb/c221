#pragma once
#include <tuple>
#include <string>
#include <utility>

class book
{
	std::tuple<std::string, std::string, size_t> data{};//author,title,year
public:
	book() = default;
	book(const std::string& author, const std::string& title, size_t year) : data(author, title, year) {}

	std::string get_author() const { return std::get<0>(data); }
	std::string get_title() const { return std::get<1>(data); }
	size_t get_year() const { return std::get<2>(data); }

	auto compare(const book& other, const size_t index = 0) const
	{

		//switch (index)
		//{
		//default:
		//	return data <=> other.data;
		//	//break;
		//case 1:
		//	if (std::get<1>(data) == std::get<1>(other.data)) return data <=> other.data;
		//	return std::get<1>(data) <=> std::get<1>(other.data);
		//	//break;
		//case 2:
		//	return std::get<2>(data) <=> std::get<2>(other.data);

		//}
	}
	auto operator<=>(const book& other) const = default;
	
};

