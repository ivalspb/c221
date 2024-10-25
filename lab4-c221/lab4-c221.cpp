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

	//с помощью std::ranges::sort() отсортируйте кружки	по площади
	std::ranges::sort(v_c, {}, &ColoredCircle::Radius);
	std::cout << "\nSorted vector of circles by square:\n";
	for (const auto& i : v_c) std::cout << i << std::endl;
	//по цвету
	std::ranges::sort(v_c, {}, &ColoredCircle::getColor);
	std::cout << "\nSorted vector of circles by color:\n";
	for (const auto& i : v_c) std::cout << i << std::endl;
	//по удалению от начала координат
	std::ranges::sort(v_c, {}, &ColoredCircle::getDist);
	std::cout << "\nSorted vector of circles by distance from (0,0):\n";
	for (const auto& i : v_c) std::cout << i << std::endl;

	//std::ranges::transform(v_c, begin(v_c), [](int a) {return a + 1; }, &ColoredCircle::Radius);
	std::ranges::transform(v_c, begin(v_c), [delta = 1](ColoredCircle& c) {c.Radius() += delta; return c; });
	std::cout << "\nIncrease radius at vector of circles by 1:\n";
	for (const auto& i : v_c) std::cout << i << std::endl;

	std::ranges::transform(v_c, begin(v_c), [x = 1, y = -1](ColoredCircle& c) {c.X() = x; c.Y() = y; return c; });
	std::cout << "\nMove centers  of circles at vector to (1,-1):\n";
	for (const auto& i : v_c) std::cout << i << std::endl;

	//перепишите в другой контейнер только те кружки, которые лежат в окружности с заданным адресом
	std::vector<ColoredCircle>v2;
	ColoredCircle c1{ Color::Red,0,0,20 };
	auto innerCircle = [](ColoredCircle& in_c, ColoredCircle& out_c) 
		{
			return in_c.getSquare()<=out_c.getSquare()
				&& (in_c.X() - in_c.Radius() >= out_c.X() - out_c.Radius())
				&& (in_c.X() + in_c.Radius() <= out_c.X() + out_c.Radius())
				&& (in_c.Y() - in_c.Radius() >= out_c.Y() - out_c.Radius())
				&& (in_c.Y() + in_c.Radius() <= out_c.Y() + out_c.Radius());
		};
	std::ranges::copy_if(v_c, std::back_inserter(v2), [](ColoredCircle& c) {return c.Radius() > 10 && c.getColor() == Blue})
	//только с заданным цветом

	/*std::vector<std::variant<ColoredRect, ColoredCircle>> vv;
	vv.push_back(ColoredCircle{ 1,2,3,Blue });
	vv.push_back(ColoredRect{ 1,2,3,4,Red });
	vv.push_back(ColoredCircle{ 34,55,8,Green });
	vv.push_back(ColoredRect{ 10,22,30,40,Green });
	vv.push_back(ColoredCircle{ 11,22,33,Red });
	vv.push_back(ColoredRect{ 1,20,35,45,Green });*/
}