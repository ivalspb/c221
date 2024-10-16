#pragma once
#include "book.h"
#include <list>
#include <map>
#include <utility>
#include <iostream>

class library
{
	std::map<book, size_t> lb;
public:
	library() = default;
	
	template <typename... books>
	library(books&&... args)
	{
		(lb[std::forward<books>(args)]++, ...);
	}
	
	template <typename... books>
	void add(books&&...bks)
	{
		(lb[std::forward<books>(bks)]++, ...);
	}

	void ByAuthor()
	{
		std::cout << "\n Library sorted by Authors:\n";
		for (const auto& [x, count] : lb)
		{
			std::cout << x << " in " << count << " pcs.\n";
		}
	}
	void ByTitle()
	{
		auto compByTitle = [](const book& b1, const book& b2) 
			{
				return b1.get_title()==b2.get_title()?b1<b2 : b1.get_title()< b2.get_title(); 
			};
		std::map<book, size_t, decltype(compByTitle)>lb_byTitle(lb.begin(),lb.end());
		std::cout << "\n Library sorted by Titles:\n";
		for (const auto& [x,count] : lb_byTitle)
		{
			std::cout<<x<< " in " << count << " pcs.\n";
		}
	}
	library(const library& other) = delete;
	library(library&& other) = delete;
	library& operator=(const library& other) = delete;
	library& operator=(library&& other) = delete;
};

