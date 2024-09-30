// Практическое занятие 1
//std::forward, std::ref, variadic функции, folds


#include <vector>
#include <utility>
#include <string>
#include <type_traits>
#include <iostream>

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
    if constexpr (sizeof...(rest)>0)
        InsertUnique(v, forward<Types>(rest)...);
}

int main()
{
    int a = 1, b = 2, c = 3;
    vector v = { ref(a),ref(b),ref(c) };
    fV(v); //в результате вызова fV a,b,c должны измениться!!!

    vector v1{ 4,7, 1 };
    InsertUnique(v1, 1.1f, string("qwerty"), 5.2, "qwerty",'c');
}
