#include <iostream>
#include "Rect.h"
#include <array>
#include <algorithm>
#include <cstdlib>

int main()
{
	std::srand(std::time(0));
	std::array<Rect, 6> ar;
	for (size_t i = 0; i < 6; i+=2)
	{
		ar[i+1]=ar[i] = {rand() % 100,rand() % 100, rand() % 100, rand() % 100, Color(rand() % 3)};
		ar[i + 1].setClr(Color::Red);
		//std::cout << ar[i].getSq() << std::endl;
	}
	std::cout << "\nBefore sorting\n";
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
}

