#pragma once
#include <vector>
#include <string_view>

template <typename... Types>
std::vector<std::string_view> make_str_vec(Types&... args)
{
	std::vector<std::string_view>s;
	((s.push_back(args)),...);
	std::vector<std::string_view::iterator> space_iterators;
	//std::vector<std::vector<std::string_view>::iterator> space_iterators;
	for (std::vector<std::string_view>::iterator it = s.begin(); it != s.end(); ++it)
	{
		for (std::string_view::iterator it_sv = (*it).begin(); it_sv != (*it).end();++it_sv)
			if(*it_sv==' ')
				space_iterators.push_back(it_sv);
	}
	std::vector<std::string_view>res;
	std::string_view::iterator word_begin = (*s.begin()).begin();
	for(auto i=space_iterators.begin();i!=space_iterators.end();++i)
	{
		res.push_back( std::string_view(word_begin,*i));
		word_begin = (*i) + 1;
	}
	res.push_back(std::string_view(word_begin, (*(s.end() - 1)).end()));
	return res;
}
