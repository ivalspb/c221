#include <iostream>
#include <vector>
#include <variant>
#include <ranges>
#include "ColoredCircle.h"
#include <algorithm>

int main()
{
	std::srand(std::time(0));
	std::vector<ColoredCircle>v_c(10);
	std::cout << "Original vector of Circles:\n";
	for (auto& i : v_c) 
	{
		i = std::move(ColoredCircle{ static_cast<Color>(rand() % 3),rand() % 100,rand() % 100,rand() % 100 });
		std::cout << i << std::endl;
	}
	std::ranges::sort(v_c, {}, &ColoredCircle::Radius);
	std::cout << "\nSorted vector of circles by square:\n";
	for (const auto& i : v_c) std::cout << i << std::endl;
	
	std::ranges::sort(v_c, {}, &ColoredCircle::getColor);
	std::cout << "\nSorted vector of circles by color:\n";
	for (const auto& i : v_c) std::cout << i << std::endl;

	std::ranges::sort(v_c, {}, &ColoredCircle::getDist);
	std::cout << "\nSorted vector of circles by distance from (0,0):\n";
	for (const auto& i : v_c) std::cout << i << std::endl;

	std::ranges::transform(v_c, v_c.begin(), [](int a) {return a + 1; }, &ColoredCircle::Radius);
}