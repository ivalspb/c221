#include <iostream>
#include "Rect.h"
#include <array>
#include <algorithm>
#include <cstdlib>
#include <string_view>
#include <string>
#include <set>
#include "str_derived_vector.h"


int main()
{
	std::srand(std::time(0));
	std::array<Rect, 6> ar;
	for (size_t i = 0; i < 6; i+=2)
	{
		ar[i+1]=ar[i] = {rand() % 100,rand() % 100, rand() % 100, rand() % 100, Color(rand() % 3)};
		ar[i + 1].setClr(Color::Red);
	}
	std::cout << "Before sorting\n";
	for (auto& x : ar)
	{
		std::cout << x << "\tSquare = " << x.getSq() << std::endl;
	}
	std::sort(ar.begin(), ar.end());
	
	std::cout << "\nAfter sorting\n";
	for (auto& x : ar)
	{
		std::cout << x<<"\tSquare = " << x.getSq() << std::endl;
	}

	const char* str[]{ "123", "abc", "qwerty" };
	char ar1[] = "dog";
	char* p = new char[] {"cat"};
	std::string s("great");
	//Требуется отсортировать все строки, не дублируя (не копируя) содержимое
	std::set<std::string_view>sorted_strings;
	sorted_strings.insert(std::begin(str), std::end(str));
	sorted_strings.insert(ar1);
	sorted_strings.insert(p);
	sorted_strings.insert(s);
	for (const auto& i : sorted_strings)
		std::cout << std::endl << i;

	//Реализуйте функцию, которая «разбивает» исходную строку на отдельные слова и 
	// создает из этих строк std::vector  - "abc”,  “12345”, “cat”, “dog”, “bird". 
	// Строки копировать нельзя!
	const char* s1 = "abc 12345 cat dog bird";
	const std::string s2 = "abc 12345 cat dog bird";

	std::vector<std::string_view> words=make_str_vec(s2);
	std::cout << "\nWords list:";
	for (auto& word : words)
		std::cout << std::endl << word;
}

