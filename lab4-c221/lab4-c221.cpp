#include <iostream>
#include <vector>
#include <variant>
#include <ranges>
#include "ColoredCircle.h"
#include <algorithm>
#include <functional>
#include "ColoredRect.h"
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
	//std::ranges::copy_if(v_c, std::back_inserter(v2), [&c1](auto& x) {return innerCircle(x, c1); });
	std::ranges::copy_if(v_c, std::back_inserter(v2), std::bind(innerCircle,std::placeholders::_1,c1));
	std::cout << "\nCopy only circles that in circle " << c1 << std::endl;
	for (const auto& i : v2) std::cout << i << std::endl;

	//только с заданным цветом
	std::cout << "\nAdd to this set another RED circles from original set:\n";
	//std::ranges::copy_if(v_c, std::back_inserter(v2), [](Color& c1) {return c1 == Color::Red; }, &ColoredCircle::getColor);
	std::ranges::copy_if(v_c, std::back_inserter(v2), [&v2](ColoredCircle& c1) 
		{return (c1.getColor() == Color::Red)&&(std::find(v2.begin(),v2.end(), c1) == v2.end()); });
	for (const auto& i : v2) std::cout << i << std::endl;

	std::vector<std::variant<ColoredRect, ColoredCircle>> vv;
	vv.push_back(ColoredCircle{ Color::Blue, 1,2,3 });
	vv.push_back(ColoredRect{ Color::Red, 1,2,3,4});
	vv.push_back(ColoredCircle{ Color::Green, 34,55,8});
	vv.push_back(ColoredRect{ Color::Blue, 10,22,30,40});
	vv.push_back(ColoredCircle{ Color::Green, 11,22,33 });
	vv.push_back(ColoredRect{ Color::Green, 1,20,35,45 });
	std::cout << "\nCreated mixed vector:\n";
	for (const auto& i : vv) 
		std::visit([](const auto& a) {std::cout << a << std::endl; },i);
	std::ranges::sort(vv, {}, [](auto const& x) {return std::visit([](auto const& e) {return e.getSquare(); }, x); });
	std::cout << "\nSorted vector of circles and rect by square:\n";
	for (const auto& i : vv)
		std::visit([](const auto& a) {std::cout << a <<" with square = "<<a.getSquare() << std::endl; }, i);
	std::ranges::sort(vv, {}, [](auto const& x) {return std::visit([](auto const& e) {return e.getColor(); }, x); });
	std::cout << "\nSorted vector of circles and rect by color:\n";
	for (const auto& i : vv)
		std::visit([](const auto& a) {std::cout << a << std::endl; }, i);

	auto red_circles = std::views::filter(v_c, [](ColoredCircle& c) {return c.getColor() == Color::Red; });
	std::cout << "\nView RED circles from original set:\n";
	for (const auto& i : red_circles) std::cout << i << std::endl;

	auto in_cicle = std::views::filter(v_c, std::bind(innerCircle, std::placeholders::_1, c1));
	std::cout << "\nView only circles that in circle " << c1 << std::endl;
	for (const auto& i : in_cicle) std::cout << i << std::endl;

	////auto sort_circle_by_square = std::views::all(v_c) | std::ranges::sort({}, [](ColoredCircle& c) {return c.getSquare(); });
	//auto sort_circle_view_by_square = std::ranges::sort(std::views::all(v_c), {}, [](ColoredCircle& c) {return c.getSquare(); });
	//std::cout << "\nView circles sorted by Square\n";
	//for (const auto& i : v_c) std::cout << i << std::endl;

	auto green_shapes = std::views::filter(vv,
		[](auto const& var)	{return	std::visit([](auto const& e) {return e.getColor(); }, var) == Color::Green; });
	std::cout << "\nVector of circles and rect of Green color:\n";
	for (const auto& i : green_shapes)
		std::visit([](const auto& a) {std::cout << a << std::endl; }, i);

	auto less_shapes = std::views::filter(vv,
		[](auto const& var) {return	std::visit([](auto const& e) {return e.getSquare(); }, var) <50 ; });
	std::cout << "\nVector of circles and rect of less then 50 square:\n";
	for (const auto& i : less_shapes)
		std::visit([](const auto& a) {std::cout << a << std::endl; }, i);

	//auto sort_shapes_view_by_square = std::ranges::sort(
	//	std::views::all(vv), {}, [](auto const& x) {return std::visit([](auto const& e) {return e.getSquare(); }, x); });
	//std::cout << "\nSorted vector of circles and rect by square:\n";
	//for (const auto& i : vv)
	//	std::visit([](const auto& a) {std::cout << a << " with square = " << a.getSquare() << std::endl; }, i);

}