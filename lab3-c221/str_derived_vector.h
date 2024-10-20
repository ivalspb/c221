#pragma once
#include <vector>
#include <string_view>

template <typename T>
std::vector<std::string_view> make_str_vec_smpl(T& arg)
{
	std::string_view s(arg);
	std::vector<std::string_view::iterator> space_iterators;
	for (std::string_view::iterator it = s.begin(); it != s.end(); ++it)
	{
		if(*it==' ')
			space_iterators.push_back(it);
	}
	std::vector<std::string_view>res;
	std::string_view::iterator word_begin = s.begin();
	for(auto i=space_iterators.begin();i!=space_iterators.end();++i)
	{
		res.push_back( std::string_view(word_begin,*i));
		word_begin = (*i) + 1;
	}
	if(word_begin!=s.end())
		res.push_back(std::string_view(word_begin, s.end()));
	return res;
}


template <typename T, typename... Types>
std::vector<std::string_view> make_str_vec(T& arg, Types&... args)
{
	std::vector<std::string_view>s= make_str_vec_smpl(arg), tmp_s;
	if constexpr (sizeof...(args) > 0)
	{
		tmp_s = make_str_vec(args...);
		s.insert(s.end(), tmp_s.begin(), tmp_s.end() );
	}
	return s;
}
