#include "tuple_print.h"
#include "Point.h"
#include "library.h"
#include <functional>
#include "calc_functions.h"
#include "my_range.h"
#include <map>
#include <cmath>


int main()
{
	std::tuple t1{ 1, 2.2, "abc" };
	printTuple(t1);
    std::cout << std::endl<<"#2"<<std::endl;
	std::tuple t2{ std::string("abc"), 1, 2.2, Point(1,2) };
	printTuple(t2);

    std::cout<<std::endl<<"#1 stream:\n"<<t1 << std::endl << "#2" << std::endl<<t2<<std::endl;

    printTuple_s(t1);

    library lEmpty;
    book my_favorite_book{ "Willims","Parallel C++", 2014 };

    library l = { book{"Straustrup", "C++", 2000}, my_favorite_book};
    //library<book> l2 = { book{"Straustrup", "C++", 2000}, my_favorite_book,book{"Straustrup", "C++", 2000} };
    //library<book> l3 = { book{"Straustrup", "C++", 2000}};
    //library<book> l4 = {  my_favorite_book,my_favorite_book,my_favorite_book };

    l.add( book{"Straustrup", "C++", 2000}, book{"Straustrup", "C++", 2010}, book{"Golovic", "xAdvanced", 2008} );
    l.ByAuthor();
    l.ByTitle();

    std::map<char, std::function<double(double, double)>>calc;
    calc['+'] = my_sum<double>;
    calc['-'] = std::minus<double>();
    calc['*'] = my_multiply<double>();
    calc['/'] = [](double a1, double a2) {return a1 / a2; };
    calc['^'] =  std::pow<double,double>;
	calc['%'] = std::bind(std::fmodf, std::placeholders::_1, std::placeholders::_2);
    calc['?'] = std::bind(&my_compare::greater, my_compare(), std::placeholders::_1, std::placeholders::_2);

    std::function<size_t(size_t)>nature_series_sum = [&nature_series_sum](size_t x)
        {
            return x < 2 ? 1 : x + nature_series_sum(x - 1);
        };
    std::cout << "Enter number for natural series sum calculation: ";
    size_t x;
    std::cin >> x;
    std::cout << "\n Sum of natural series of " << x << " = " << nature_series_sum(x);

    bool check_range = InRange(10, 20, 1, 15, 30);    // --> false 
    check_range = InRange(10, 20, 11, 12, 13);   // --> true
    check_range = InRange(5.0, 5.5, 5.1, 5.2, 5.3); // --> true

}

