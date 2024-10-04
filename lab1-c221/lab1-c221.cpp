// Практическое занятие 1
//std::forward, std::ref, variadic функции, folds


#include <vector>
#include <utility>
#include <string>
#include <type_traits>
#include <iostream>
#include "MyStack.h"


using namespace std;

template<typename T> void fV(vector<T>& v) {
    for (auto& x : v) { ++x; }
}


template<typename U, typename T, typename... Types>
constexpr void InsertUnique(vector<U>& v, T&& current, Types&&... rest)
{
    if constexpr (is_convertible_v<U, T>)
    {
        auto d = find(v.begin(), v.end(), static_cast<U>(current));
        if (d == v.end())
            v.push_back(current);
    }
    if constexpr (sizeof...(rest) > 0)
        InsertUnique(v, forward<Types>(rest)...);
}

template <typename U, typename T, typename... Types>
constexpr void functions_with_arg(U& x, T&& cur_func, Types&&... rest_functions)
{
    forward<T>(cur_func)(x);
    if constexpr (sizeof...(rest_functions) > 0)
        functions_with_arg(x, forward<Types>(rest_functions)...);
}

template <typename U, typename... Types>
constexpr void functions_with_arg_folded(U& x, Types&&... functions)
{
    (forward<Types>(functions)(x), ...);
}

template <typename U, typename T, typename... Types>
constexpr void func_any_param(U&& func, T&& cur, Types&&... rest)
{
    forward<U>(func)(cur);
    if constexpr (sizeof...(rest) > 0)
        func_any_param(forward<U>(func), forward<Types>(rest)...);
}

template <typename U, typename... Types>
constexpr void func_any_param_folded(U&& func, Types&&... rest)
{
    (forward<U>(func)(forward<Types>(rest)), ...);
}



template <typename T>
void decr_any(T& t)
{
    t--;
}

int main()
{
    int a = 1, b = 2, c = 3;
    vector<std::reference_wrapper<int>> v = { ref(a),ref(b),ref(c) };
    fV(v); //в результате вызова fV a,b,c должны измениться!!!

    vector v1{ 4,7, 1 };
    InsertUnique(v1, 1.1f, string("qwerty"), 5.2, "qwerty", 'c');

    double d1 = 1.1, d2 = 2.2, d3 = 3.3;
    double delta = 3;


    functions_with_arg(d1, [delta](auto& d) {d += delta; }, decr_any<double>);
    functions_with_arg_folded(d3, [delta](auto& d) {d -= delta; }, decr_any<double>);

    func_any_param(decr_any<double>, d1, d2, d3);
    func_any_param_folded([delta](auto& d) {d *= delta; }, d1, d2, d3);

    //требуется определить сколько элементов совпадающих с перечисленными в паке значениями содержит последовательность (обобщенный контейнер).
    /*vector v{ 1,2,3,4,5 };
    size_t n1 = mathches(v, 2, 5);
    size_t n2 = mathches(v, 100, 200);
    size_t n3 = mathches("abcdefg", 'x', 'y', 'z');
    size_t n4 = mathches("abcdefg", 'a', 'd', 'f');*/

    MyStack<Point<int>> s;
    Point<int> pt(1, 1);
    s.push(pt); //добавить в стек копию lvalue
    s.push(Point(2, 2)); //переместить в стек из rvalue
    Point pt1(4, 4);
    s.push(pt, Point(5, 5), pt1, Point(6, 6));
    MyStack <Point<int>> s1(pt, Point(7, 7), pt1, Point(8, 8));
}
