#include <iostream>
#include "Rect.h"
#include <array>
#include <algorithm>
#include <cstdlib>
#include <string_view>
#include <string>
#include <set>
#include "str_derived_vector.h"
#include "my_optional.h"
#include "person.h"
#include "dog.h"
#include "cat.h"
#include <list>
#include <variant>
#include "my_time.h"


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
	const char* s1 = "The first string ... ";
	const std::string s2 = "abc 12345 cat dog bird";

	std::vector<std::string_view> words=make_str_vec(s1,s2,ar1,p,s);
	std::cout << "\nWords list:";
	for (auto& word : words)
		std::cout << std::endl << word;

	std::vector v{ 1,2,3,4,5 };
	std::optional<size_t> id1 = get_index_by_abs_value(v, 3);
	std::optional<size_t> id2 = get_index_by_abs_value(v, 6);
	std::optional<size_t> id3 = get_index_by_abs_value(v, -2);

	std::vector<person> persons{ person{"Nikolay",36,"nik"},person{"Erofey",58},person{"Anna",40,"Ann"},person{"Nikolay",36} };
	for (auto& i : persons) std::cout << std::endl << i;
	std::sort(persons.begin(), persons.end());
	std::cout << "\nSorted:\n";
	for (auto& i : persons) std::cout << std::endl << i;

	std::list<std::variant<cat, dog>>animal_l;
	animal_l.push_back(cat("Musya"));
	animal_l.push_back(dog("Sharik"));
	animal_l.push_back(dog("Buldog"));
	std::cout << "\n\nAnimals list:\n";
	size_t cats = 0, dogs = 0;
	for (auto i : animal_l)
	{
		if (std::get_if<cat>(&i)) cats++;
		else dogs++;
		std::visit([](const auto& x) {std::cout << x; }, i);
	}
	std::cout  << cats << " Cats and " << dogs << " Dogs";

	auto prnt = [](const auto& a) {std::cout << a << ":"; };
	std::cout << "\nPrinting current date:\n";
	std::visit(prnt, get_my_date(What::Day));
	std::visit(prnt, get_my_date(What::Month));
	std::visit(prnt, get_my_date(What::Year));
	std::visit(prnt, get_my_date(What::WeekDay));
}

