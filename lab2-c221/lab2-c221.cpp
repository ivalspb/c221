#include "tuple_print.h"
#include "Point.h"
#include "library.h"



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
}

